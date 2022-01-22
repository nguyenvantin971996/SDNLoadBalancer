import matplotlib.pyplot as plts
import matplotlib
import numpy as np
font = {'size'   : 11}
matplotlib.rc('font', **font)
class draw:
    def __init__(self,a1,a2,a3,parameter,name_parameter):
        self.a1 = a1
        self.a2 = a2
        self.a3 = a3
        self.parameter = parameter
        self.name_parameter = name_parameter
        self.a = np.array(range(len(self.a1)))

    def Do(self):
        if(len(self.a1)%2==0):
            figg1 = plts.figure()
            self.a = self.a+1
            plts.plot(self.a, self.a1, label=self.name_parameter+" = "+str(self.parameter[0]),linewidth = '2')
            plts.plot(self.a, self.a2, label=self.name_parameter+" = "+str(self.parameter[1]),linewidth = '2')
            plts.plot(self.a, self.a3, label=self.name_parameter+" = "+str(self.parameter[2]),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)
        else:
            figg2 = plts.figure()
            plts.plot(self.a, self.a1, label=self.name_parameter+" = "+str(self.parameter[0]),linewidth = '2')
            plts.plot(self.a, self.a2, label=self.name_parameter+" = "+str(self.parameter[1]),linewidth = '2')
            plts.plot(self.a, self.a3, label=self.name_parameter+" = "+str(self.parameter[2]),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)

    def Do_2(self): 
        if(len(self.a1)%2==0):
            figg3 = plts.figure()
            self.a = self.a+1
            plts.plot(self.a, self.a1, label=self.name_parameter+" = "+str(self.parameter),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)
        else:
            figg4 = plts.figure()
            plts.plot(self.a, self.a1, label=self.name_parameter+" = "+str(self.parameter),linewidth = '2')
            plts.legend(loc="upper right")
            plts.xlabel("iteration")
            plts.ylabel("CD")
            plts.grid()
            plts.savefig(self.name_parameter+".png",dpi=200)