import numpy as np
import tensorflow as tf

from tensorflow.keras.models import Model, load_model
from tensorflow.keras.layers import Dense, Input, BatchNormalization, Activation, Lambda
from tensorflow.keras.initializers import RandomUniform
from tensorflow.keras.optimizers import Adam
from tensorflow.keras import layers

"""
Actor network:
stochastic funcion approssimator for the deterministic policy map u : S -> A
(with S set of states, A set of actions)
"""
class Actor(object):
    def __init__(self, state_dims, action_dims, lr, batch_size, tau,
                    fcl1_size, fcl2_size, upper_bound):
        self.state_dims = state_dims
        self.action_dims = action_dims
        self.lr = lr
        # learning rate
        self.batch_size = batch_size
        self.tau = tau
        # polyak averaging speed
        self.fcl1_size = fcl1_size
        self.fcl2_size = fcl2_size
        self.upper_bound = upper_bound

        self.model = self.build_network()
        self.model.summary()
        #duplicate model for target
        self.target_model = self.build_network()
        self.target_model.set_weights(self.model.get_weights())

        self.optimizer = Adam(self.lr)


    def build_network(self):
        # Initialize weights between -3e-3 and 3-e3
        last_init = tf.random_uniform_initializer(minval=-0.003, maxval=0.003)

        inputs = layers.Input(shape=self.state_dims)
        out = layers.Dense(self.fcl1_size, activation="relu")(inputs)
        out = layers.Dense(self.fcl2_size, activation="relu")(out)
        outputs = layers.Dense(self.action_dims[0], activation="sigmoid", kernel_initializer=last_init)(out)

        # Our upper bound is 2.0 for Pendulum.
        # outputs = outputs * self.upper_bound
        model = tf.keras.Model(inputs, outputs)
        return model

    @tf.function
    def train(self, states, critic_model):
        """
        Update the weights with the new critic evaluation
        """
        with tf.GradientTape() as tape:
            actions = self.model(states, training=True)
            q_value = critic_model([states, actions], training=True)
            loss = -tf.math.reduce_mean(q_value)
        gradient = tape.gradient(loss, self.model.trainable_variables)
        self.optimizer.apply_gradients(zip(gradient, self.model.trainable_variables))

    def update_target(self):
        """
        Update the target weights using tau as speed. The tracking function is
        defined as:
        target = tau * weights + (1 - tau) * target
        """
        # faster updates woth graph mode
        self._transfer(self.model.variables, self.target_model.variables)

    @tf.function
    def _transfer(self, model_weights, target_weights):
        for (weight, target) in zip(model_weights, target_weights):
            #update the target values
            target.assign(weight * self.tau + target * (1 - self.tau))
    
    def restore(self):
        self.model.save('actor_model.h5')
