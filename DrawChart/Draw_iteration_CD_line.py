import matplotlib.pyplot as plts
import matplotlib
import numpy as np
font = {'size'   : 11}
matplotlib.rc('font', **font)
class draw:
    def __init__(self,a1,parameter,name_parameter):
        self.a1 = a1
        self.parameter = parameter
        self.name_parameter = name_parameter
        self.a = np.array(range(len(self.a1[0])))

    def Do(self):
        if(len(self.a1[0])%2==0):
            figg1 = plts.figure()
            self.a = self.a+1
            for i in range(len(self.a1)):
                plts.plot(self.a, self.a1[i], label=self.name_parameter+" = "+str(self.parameter[i]),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)
        else:
            figg2 = plts.figure()
            for i in range(len(self.a1)):
                plts.plot(self.a, self.a1[i], label=self.name_parameter+" = "+str(self.parameter[i]),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)