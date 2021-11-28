from keras.models import load_model
model = load_model('my_model.h5')
import random
import numpy as np
import pandas as pd
import copy
import time
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
column=[(1,2),(1,3),(1,4),(2,4),(2,5),(3,4),(3,5),(4,5)]
value = np.array([0,0,0,0,0,0,0,0])
with open('metric_data.txt') as f:
    for line in f:
        strt = line
        strt2 = strt.split(':')
        my_result = tuple(map(int, strt2[0].split(',')))
        for i in range(len(column)):
        	if(column[i]==my_result):
        		value[i] = int(strt2[1])
value_1 = value.reshape(-1,1)
value_1 = sc.fit_transform(value_1)
pred=model.predict(value_1.reshape(1,-1))
pred = pred.round()
path_wire = []
path_cost = 0
for i in range(len(pred[0])):
    if (pred[0][i]==1):
        path_cost+=value[i]
        path_wire.append(column[i])
path_router = [1]
for x in path_wire:
    path_router.append(x[1])
paths=[]
paths.append(path_router)
f=open("demo.txt","w")
f.truncate(0)
for path in paths:
    stt = ",".join(str(x) for x in path)
    stt= stt+","+str(path_cost)+"\n"
    f.write(stt)
f.close()
print(value)
print(path_cost)
print(path_router)
print(path_wire)