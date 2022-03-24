import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

font = {'size'   : 11}
matplotlib.rc('font', **font)
class BarChart:
    def __init__(self, values, stt):
        self.values = values
        self.stt = stt + ".png"

    def Do(self):
        NumberPaths = len(self.values)
        fig = plt.figure(figsize=(10,8))
        ax = plt.axes(projection="3d")
        x = np.zeros(NumberPaths)+NumberPaths
        y = np.array(range(NumberPaths))*2.8+3
        z = np.zeros(NumberPaths)

        dx = np.ones(NumberPaths)+2
        dy = np.ones(NumberPaths)+0.7
        dz = np.array(self.values)

        colors = ['blue','cyan','lime','gray','yellow','hotpink','chocolate',
        'lightgreen','red','yellowgreen','violet','slategray','lightgreen','navy','gold','peru',
        'pink','brown','teal','tan','forestgreen','thistle','salmon','dimgray','tomato','orange',
        'silver','slategrey','indigo','lightpink','purple','royalblue','khaki','olive','palegreen',
        'firebrick','steelblue','seagreen','crimson','dimgray'
        ]
        ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([1, 1.5, 1, 1]))
        ax.bar3d(x,y,z,dx,dy,dz,color = colors[:NumberPaths],alpha = 0.7)
        ax.set_xlim(0,NumberPaths*2)
        ax.set_ylim(0,NumberPaths*3+0.5*NumberPaths)
        ax.view_init(10,10)
        ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ylabels = []
        y1 = []
        for i in range(NumberPaths):
            if(i%2==0):
                st = str(i+1)
                ylabels.append(st)
                y1.append(y[i])
        y1 = np.array(y1)
        xlabels = ['0']
        ax.yaxis.set_ticks(y1+0.5)
        ax.xaxis.set_ticks([NumberPaths])
        ax.xaxis.set_ticklabels(xlabels)
        ax.yaxis.set_ticklabels(ylabels)
        for i in range(NumberPaths):
            ax.text(x[i]-0.05*NumberPaths, y[i]-0.75/NumberPaths, dz[i], str(dz[i]),color='black',size = 8, backgroundcolor= 'orange', rotation='vertical', horizontalalignment='left', verticalalignment='bottom')
        ax.set_zlabel("Ds")
        ax.set_ylabel("Path No.")
        plt.savefig(self.stt,dpi = 200)
#         plt.show()

# cc = BarChart([430,450,440,470,450,440, 430,450,440,470],"xxx")
# cc.Do()