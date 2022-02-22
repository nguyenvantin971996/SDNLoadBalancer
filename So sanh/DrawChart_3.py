import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

font = {'size'   : 11}
matplotlib.rc('font', **font)
class BarChart:
    def __init__(self, values_1, values_2, values_3,stt,pr):
        self.values_1 = values_1
        self.values_2 = values_2
        self.values_3 = values_3
        self.values_1.reverse()
        self.values_2.reverse()
        self.values_3.reverse()
        self.stt = stt + ".png"
        self.pr = pr

    def Do(self):
        NumberPaths = len(self.values_1)
        x1 = np.zeros(NumberPaths)+NumberPaths
        x2 = np.zeros(NumberPaths)+2*NumberPaths
        x = np.zeros(NumberPaths)
        x = np.concatenate((x, x1), axis=0)
        x = np.concatenate((x, x2), axis=0)

        y1 = np.array(range(NumberPaths))*3+3
        y2 = np.array(range(NumberPaths))*3+3
        y = np.array(range(NumberPaths))*3+3
        y = np.concatenate((y, y1), axis=0)
        y = np.concatenate((y, y2), axis=0)
        z = np.zeros(3*NumberPaths)

        dx = np.ones(3*NumberPaths)+ 2
        dy = np.ones(3*NumberPaths)+0.7
        va = []
        va.extend(self.values_1)
        va.extend(self.values_2)
        va.extend(self.values_3)
        dz1 = np.array(va)
        colors = ['blue','cyan','lime','gray','yellow','hotpink','chocolate',
        'lightgreen','red','yellowgreen','blue','cyan','lime','gray','yellow','hotpink','chocolate',
        'lightgreen','red','yellowgreen','blue','cyan','lime','gray','yellow','hotpink','chocolate',
        'lightgreen','red','yellowgreen'
        ]
        colors.reverse()
        ylabels = []
        y1 = []
        for i in range(NumberPaths):
            if(i%2==0):
                st = str(i+1)
                ylabels.append(st)
                y1.append(y[i])
        y1.reverse()
        y1 = np.array(y1)
        xlabels = self.pr[:3]

        fig = plt.figure(figsize=(8,8))
        ax = plt.axes(projection="3d")
        ax.bar3d(y,x,z,dy,dx,dz1,color = colors[:3*NumberPaths],alpha = 0.7)
        ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.xaxis.set_ticks(y1+3.5)
        ax.yaxis.set_ticks([2,NumberPaths+2,2*NumberPaths+2])
        ax.yaxis.set_ticklabels(xlabels)
        ax.xaxis.set_ticklabels(ylabels)
        for i in range(3*NumberPaths):
            ax.text(y[i], x[i]+2, dz1[i], str(dz1[i]),color='black',size = 6, backgroundcolor= 'orange', rotation='vertical', horizontalalignment='left', verticalalignment='bottom')
        ax.set_zlabel("Ds")
        ax.set_xlabel("Path No.")
        ax.set_ylabel(self.pr[-1])

        plt.savefig(self.stt,dpi = 200)
        # plt.show()
# pr = ['10','20','30','N']
# cc = BarChart([430,450,440,470,450,440,430,450,440,470],[430,450,440,470,450,440,430,450,440,470],[430,450,440,470,450,440,430,450,440,470],"xxx",pr)
# cc.Do()