import matplotlib.pyplot as plt
import numpy as np
class BarChart:
    def __init__(self, values, stt):
        self.values = values
        self.stt = stt

    def Do(self):
        fig = plt.figure()
        ax = plt.axes(projection="3d")
        NumberPaths = len(self.values)
        x = np.zeros(NumberPaths)+NumberPaths
        y = np.array(range(NumberPaths))*2
        z = np.zeros(NumberPaths)

        dx = np.ones(NumberPaths)+1
        dy = np.ones(NumberPaths)
        dz = np.array(self.values)

        colors = ['red','orange','lime','blue','yellow','green','chocolate',
        'olive','gray','cyan','violet','slategray','lightgreen','navy','gold','peru',
        'pink','brown','teal','tan','forestgreen','thistle','salmon','dimgray','tomato','purple',
        'silver','slategrey','indigo','lightpink'
        ]
        ax.bar3d(x,y,z,dx,dy,dz,color = colors[:NumberPaths])
        ax.set_xlim(0,NumberPaths*2)
        ax.set_ylim(0,NumberPaths*2)
        ax.view_init(10,10)
        ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
        ylabels = []
        for i in range(NumberPaths):
            st = str(i+1)
            ylabels.append(st)
        xlabels = ['0']
        ax.yaxis.set_ticks(y+0.5)
        ax.xaxis.set_ticks([NumberPaths])
        ax.xaxis.set_ticklabels(xlabels)
        ax.yaxis.set_ticklabels(ylabels)
        for i in range(NumberPaths):
            ax.text(x[i], y[i]+1/NumberPaths, dz[i], str(dz[i]),color='black', backgroundcolor= 'orange', weight= 'bold', rotation='vertical', fontsize=2+20/NumberPaths, horizontalalignment='left', verticalalignment='bottom')
        plt.savefig(self.stt,dpi = 900)
        # plt.show()
# cc = BarChart([13,45,24,67,45,24,67],"xxx")
# cc.Do()