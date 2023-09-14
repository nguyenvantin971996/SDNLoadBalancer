from Agent import Agent
import os
import numpy as np
import json
from Env import Env
import matplotlib.pyplot as plt
from statistics import mean
from time import sleep
while True:
    sleep(2)
    action = np.random.uniform(1,10,size = 6).tolist()
    print(action)
    d = {}
    d['[1, 7]'] = action[0:2]
    d['[2, 5]'] = action[2:4]
    d['[3, 4]'] = action[4:6]
    d['[7, 1]'] = action[0:2]
    d['[5, 2]'] = action[2:4]
    d['[4, 3]'] = action[4:6]
    print(d)
    with open("act.json", "w") as outfile:
        json.dump(d,outfile)
    outfile.close()