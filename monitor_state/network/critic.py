import numpy as np
import keras.backend as K
import tensorflow as tf

from tensorflow.keras.models import Model
from tensorflow.keras.layers import Dense, Input, BatchNormalization, Activation, Add, Flatten
from tensorflow.keras.initializers import RandomUniform
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import MSE
from tensorflow.keras import layers

class Critic(object):
    """
    Critic network:
    stochastic funcion approssimator for the Q value function C : SxA -> R
    (with S set of states, A set of actions)
    """
    def __init__(self, state_dims, action_dims, lr, batch_size, tau,
                fcl1_size, fcl2_size):
        self.state_dims = state_dims
        self.action_dims = action_dims
        # learning rate
        self.lr = lr
        self.batch_size = batch_size
        # polyak averaging speed
        self.tau = tau
        self.fcl1_size = fcl1_size
        self.fcl2_size = fcl2_size

        self.model = self.build_network()
        self.model.summary()
        #duplicate model for target
        self.target_model = self.build_network()
        self.target_model.set_weights(self.model.get_weights())

        #generate gradient function
        self.optimizer = Adam(self.lr)

    def build_network(self):
        state_input = layers.Input(shape=self.state_dims)
        state_out = layers.Dense(32, activation="relu")(state_input)

        # Action as input
        action_input = layers.Input(shape=self.action_dims)
        action_out = layers.Dense(32, activation="relu")(action_input)

        # Both are passed through seperate layer before concatenating
        concat = layers.Concatenate()([state_out, action_out])

        out = layers.Dense(self.fcl1_size, activation="relu")(concat)
        out = layers.Dense(self.fcl2_size, activation="relu")(out)
        outputs = layers.Dense(1)(out)

        # Outputs single value for give state-action
        model = tf.keras.Model([state_input, action_input], outputs)

        return model

    @tf.function
    def train(self, states, actions, rewards, terminals, states_n, actor_target, gamma):
        """
        Update the weights with the Q targets. Graphed function for more
        efficient Tensor operations
        """
        with tf.GradientTape() as tape:
            target_actions = actor_target(states_n, training=True)
            q_n = self.target_model([states_n, target_actions], training=True)
            # Bellman equation for the q value
            q_target = rewards + gamma * q_n * (1 - terminals)
            q_value = self.model([states, actions], training=True)
            loss = MSE(q_target, q_value)

        gradient = tape.gradient(loss, self.model.trainable_variables)
        self.optimizer.apply_gradients(zip(gradient, self.model.trainable_variables))

    def update_target(self):
        """
        Update the target weights using tau as speed. The tracking function is
        defined as:
        target = tau * weights + (1 - tau) * target
        """
        # faster updates with graph mode
        self._transfer(self.model.variables, self.target_model.variables)

    @tf.function
    def _transfer(self, model_weights, target_weights):
        """
        Target update helper. Applies Polyak averaging on the target weights.
        """
        for (weight, target) in zip(model_weights, target_weights):
            #update the target values
            target.assign(weight * self.tau + target * (1 - self.tau))
    
    def restore(self):
        self.model.save('critic_model.h5')
