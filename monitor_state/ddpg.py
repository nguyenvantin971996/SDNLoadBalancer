from Agent import Agent
import os
import numpy as np
import json
from Env import Env
import matplotlib.pyplot as plt
from statistics import mean
from time import sleep
import time

N_EPISODES = 20
class DDPG(object):
    def __init__(self):
        pass
    def main(self):
        env = Env()
        sleep(4)
        state_dims = [20]
        action_dims = [10]
        action_boundaries = [[0.01], [1]]
        print(state_dims, action_dims)
        print(action_boundaries)
        agent = Agent(state_dims = state_dims, action_dims = action_dims,
                    action_boundaries = action_boundaries, actor_lr = 0.001,
                    critic_lr = 0.01, batch_size = 64, gamma = 0.99, rand_steps = 2,
                    buf_size = int(1e6), tau = 0.001, fcl1_size = 64, fcl2_size = 64)
        episode = 0
        scores = []
        for i in range(N_EPISODES):
            score = []
            print(episode)
            start = time.time()
            env.ob.create_traffic()
            sleep(4)
            state = env.reset()
            terminal = False
            while not terminal:
                act = agent.get_action(state, episode)
                action = act.tolist()
                env.step(action)
                sleep(6)
                end = time.time()
                if(end - start) < 200:
                    state_new, reward, terminal = env.get_rs()
                    state_new = np.array(state_new)
                    agent.remember(state, state_new, act, reward, terminal)
                    agent.learn()
                    score.append(reward)
                    state = state_new
                    # print([round(x,2) for x in state])
                    print([round(x,2) for x in action], reward)
                    print('==============================================')
                else:
                    terminal = True
            episode+=1
            scores.append(sum(score))
            sleep(10)
        agent.actor.model.save('network/actor_model.h5')
        agent.critic.model.save('network/critic_model.h5')
        plt.plot(scores)
        plt.xlabel("Episode")
        plt.ylabel("Scores")
        plt.show()
ddpg = DDPG()
ddpg.main()