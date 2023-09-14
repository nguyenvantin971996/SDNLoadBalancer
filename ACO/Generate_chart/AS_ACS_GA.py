import os
import random
import time

from AS import AS
from ACS import ACS
from GA import GA
from Draw_3D_chart import BarChart

N = 40
Max = 1000
K_paths = 10
Pc = 0.9
Pm = 0.9
Ts = 5
p = 0.1
a = 0.1
b = 0.5
p0 = 0.9
Q = 1
dst = 1
src = 10
alg_1 = AS(dst,src,N, Max, K_paths, p, a, b, p0, Q)
alg_1.Do()
alg_2 = ACS(dst,src,N, Max, K_paths, p, a, b, p0, Q)
alg_2.Do()
alg_3 = GA(dst,src,N, Max, K_paths, Pc, Pm, Ts)
alg_3.Do()
pr = ["AS","ACS","GA"]
pr.append("Type of algorithm")
chart = BarChart(alg_1.values,alg_2.values,alg_3.values,"AS_ACS_GA",pr)
chart.Do()
f=open("../../demo.txt","w")
f.truncate(0)
for i in range(len(alg_2.best)):
    stt = ",".join(str(x) for x in alg_2.best[i].path)
    stt= stt+","+str(alg_2.best[i].fitness)+"\n"
    f.write(stt)
f.close()