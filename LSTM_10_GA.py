import os
from tabnanny import verbose
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
import tensorflow as tf
from tensorflow.keras.models import load_model
import random
import numpy as np
import pandas as pd
import copy
import time
from sklearn.preprocessing import StandardScaler
from Results import Results
model = load_model('model_LSTM_6.h5',compile = False)
vertices = [1,2,3,4,5,6,7,8]
# edges = [[1, 2], [1, 5], [1, 8], [2, 3], [3, 4], [3, 8], [3, 9], [4, 10], [5, 6], [6, 7], [6, 8], [6, 9], [7, 10], [9, 10]]
edges = [[1, 2], [1, 3], [2, 4], [2, 5], [3, 4], [3, 7], [4, 6], [5, 6], [5, 8], [6, 7], [7, 8]]
number_edges = len(edges)
number_steps = 4
start_node = 1
end_node = 8
class LSTM(object):
    value_0 = np.zeros(number_edges)
    with open('metric_data.txt') as f:
        for line in f:
            strt = line
            strt2 = strt.split(':')
            my_result = list(map(int, strt2[0].split(',')))
            for i in range(number_edges):
                if(my_result==edges[i]):
                    value_0[i] = float(strt2[1])
    sc = StandardScaler()
    value_1 = sc.fit_transform(value_0[:, np.newaxis]).T
    value_1 = np.repeat(value_1[:, np.newaxis, :], number_steps, axis=1)
    pred = model.predict(value_1)
    pred = pred.round()
    paths = []
    pw = []
    r = Results(number_edges, edges, start_node, end_node, number_steps)
    for i in range(pred.shape[1]):
        cost, path = r.cost_path(value_0,pred[0][i])
        if cost!= 0:
            paths.append(path)
            pw.append(int(cost))
        else:
            paths.append([])
            pw.append(0)
    f=open("demo.txt","w")
    f.truncate(0)
    for i in range(len(paths)):
        if len(paths[i])==0:
            f.write("It is invalid path.\n")
        else:
            stt = ",".join(str(x) for x in paths[i])
            stt= stt+","+str(pw[i])+"\n"
            f.write(stt)
    f.close()