import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

font = {'size'   : 11}
matplotlib.rc('font', **font)
class BarChart:
    def __init__(self, values_1, values_2, stt):
        self.values_1 = values_1
        self.values_2 = values_2
        self.stt = stt + ".png"

    def Do(self):
        NumberPaths = len(self.values_1)
        x = np.zeros(NumberPaths)+NumberPaths
        y = np.array(range(NumberPaths))*3.2+3
        z = np.zeros(NumberPaths)

        dx = np.ones(NumberPaths)+ 3
        dy = np.ones(NumberPaths)+0.7
        dz1 = np.array(self.values_1)
        dz2 = np.array(self.values_2)

        colors = ['blue','cyan','lime','gray','yellow','hotpink','chocolate',
        'lightgreen','red','yellowgreen','violet','slategray','lightgreen','navy','gold','peru',
        'pink','brown','teal','tan','forestgreen','thistle','salmon','dimgray','tomato','orange',
        'silver','slategrey','indigo','lightpink','purple','royalblue','khaki','olive','palegreen',
        'firebrick','steelblue','seagreen','crimson','dimgray'
        ]
        ylabels = []
        y1 = []
        for i in range(NumberPaths):
            if(i%2==0):
                st = str(i+1)
                ylabels.append(st)
                y1.append(y[i])
        y1 = np.array(y1)
        xlabels = ['0']

        fig = plt.figure(figsize=(16,8))
        ax = fig.add_subplot(121,projection="3d")
        ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([1, 1.3, 1, 1]))
        ax.bar3d(x,y,z,dx,dy,dz1,color = colors[:NumberPaths],alpha = 0.7)
        ax.set_xlim(0,NumberPaths*2)
        ax.set_ylim(0,NumberPaths*3+0.5*NumberPaths)
        ax.view_init(10,10)
        ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.yaxis.set_ticks(y1+0.5)
        ax.xaxis.set_ticks([NumberPaths])
        ax.xaxis.set_ticklabels(xlabels)
        ax.yaxis.set_ticklabels(ylabels)
        for i in range(NumberPaths):
            ax.text(x[i]-0.05*NumberPaths, y[i]-3/NumberPaths, dz1[i], str(dz1[i]),color='black',size = 8, backgroundcolor= 'orange', rotation='vertical', horizontalalignment='left', verticalalignment='bottom')
        ax.set_zlabel("Ds")
        ax.set_ylabel("Path No.")
        ax.text2D(0.5, 0.85, "Max = 10 (CD = "+str(sum(self.values_1))+")", transform=ax.transAxes)

        ax1 = fig.add_subplot(122,projection="3d")
        ax1.get_proj = lambda: np.dot(Axes3D.get_proj(ax1), np.diag([1, 1.3, 1, 1]))
        ax1.bar3d(x,y,z,dx,dy,dz2,color = colors[:NumberPaths],alpha = 0.7)
        ax1.set_xlim(0,NumberPaths*2)
        ax1.set_ylim(0,NumberPaths*3+0.5*NumberPaths)
        ax1.view_init(10,10)
        ax1.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax1.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax1.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax1.yaxis.set_ticks(y1+0.5)
        ax1.xaxis.set_ticks([NumberPaths])
        ax1.xaxis.set_ticklabels(xlabels)
        ax1.yaxis.set_ticklabels(ylabels)
        for i in range(NumberPaths):
            ax1.text(x[i]-0.05*NumberPaths, y[i]-3/NumberPaths, dz2[i], str(dz2[i]),color='black',size = 8, backgroundcolor= 'orange', rotation='vertical', horizontalalignment='left', verticalalignment='bottom')
        ax1.set_zlabel("Ds")
        ax1.set_ylabel("Path No.")
        ax1.text2D(0.5, 0.85, "Max = 100 (CD = "+str(sum(self.values_2))+")", transform=ax1.transAxes)
        plt.savefig(self.stt,dpi = 200)
        # plt.show()

# cc = BarChart([430,450,440,470,450,440,430,450,440,470],[430,450,440,470,450,440,430,450,440,470],"xxx")
# cc.Do()