from keras.models import load_model
model = load_model('model_NN_GA_8_8_8.h5')
import random
import numpy as np
import pandas as pd
import copy
import time
from sklearn.preprocessing import StandardScaler

MAX_PATHS = 1
class FCN_GA(object):
    def __init__(self, adjacency,switches):
        self.switches = switches
        self.adjacency = adjacency
        self._distance = {}
        self._previous = {}
        self._viewed_switches = []
        self.value = np.array([0,0,0,0,0,0,0,0])
        self.path_cost = 0

    def get_paths(self, src, dst):
        paths = []
        sc = StandardScaler()
        column=[(1,2),(1,3),(1,4),(2,4),(2,5),(3,4),(3,5),(4,5)]
        with open('metric_data.txt') as f:
            for line in f:
                strt = line
                strt2 = strt.split(':')
                my_result = tuple(map(int, strt2[0].split(',')))
                for i in range(len(column)):
                    if(column[i]==my_result):
                        self.value[i] = int(strt2[1])
        value_1 = self.value.reshape(-1,1)
        value_1 = sc.fit_transform(value_1)
        pred = model.predict(value_1.reshape(1,-1))
        pred = pred.round()
        path_wire = []
        for i in range(len(pred[0])):
            if (pred[0][i]==1):
                self.path_cost+=self.value[i]
                path_wire.append(column[i])
        path_router = [path_wire[0][0]]
        for x in range(len(path_wire)):
            if(x!=len(path_wire)-1):
                if(path_wire[x][1]!=path_wire[x+1][0]):
                    break
            path_router.append(path_wire[x][1])
        if (path_router[0]==dst):
            path_router.reverse()
        paths.append(path_router)
        return paths

    def get_path_cost(self, path):
        return self.path_cost