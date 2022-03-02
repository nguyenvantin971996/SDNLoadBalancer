import numpy as np
import random
import math
import copy

class Ant(object):
    def __init__(self):
        self.path = []
        self.fitness = float('inf')
        self.delta = 0


class ACS:

    def __init__(self,adjacency, switches,src, dst, N, Max, K_paths, p, a, b, p0, Q):
        self.adjacency = adjacency
        self.switches = switches
        self.src= src
        self.dst = dst
        self.weight_map= self.GetWeightMap()
        self.N = N
        self.Max = Max
        self.K_paths = K_paths
        self.p = p
        self.a = a
        self.b = b
        self.p0 = p0
        self.Q = Q
        self.colony = [Ant() for i in range(self.N)]
        self.condidates = []
        self.best = []
        self.Lnn = self.FindLnn()
        self.t0 = 1/(len(self.switches)*self.Lnn)
        self.pheromone = self.CreatePheromone()
    
    def FindLnn(self):
        path = []
        current_switch = self.src
        path.append(current_switch)
        while(current_switch!=self.dst):
            neighbor_switches = set(self.adjacency[current_switch].keys())-set(path)
            neighbor_switches = list(neighbor_switches)
            if(len(neighbor_switches)==0):
                path.clear()
                current_switch = self.src
                path.append(current_switch)
            else:
                current_switch = self.GetNextSwitchLnn(neighbor_switches, current_switch)
                path.append(current_switch)
        Lnn = self.Evaluate(path)
        return Lnn
                
    def GetNextSwitchLnn(self, neighbor_switches, current_switch):
        next_switch = neighbor_switches[0]
        for sw in neighbor_switches:
            if(self.weight_map[current_switch][sw]<=self.weight_map[current_switch][next_switch]):
                next_switch = sw
        return next_switch

    def CreatePheromone(self):
        pheromone = copy.deepcopy(self.adjacency)
        for sw_1 in self.adjacency.keys():
            for sw_2 in self.adjacency[sw_1].keys():
                pheromone[sw_1][sw_2] = self.t0
        return pheromone
    
    def GetWeightMap(self):
        weight_map={}
        temp = 0
        with open('../metric_data.txt') as f:
            for line in f:
                strt = line
                strt2 = strt.split(':')
                my_result = list(map(int, strt2[0].split(',')))
                if (temp!=my_result[0]):
                    weight_map[my_result[0]]={}
                weight_map[my_result[0]][my_result[1]] = int(strt2[1])
                temp = my_result[0]
        return weight_map

    def CreatePath(self):
        for i in range(self.N):
            path = []
            current_switch = self.src
            path.append(current_switch)
            while(current_switch!=self.dst):
                neighbor_switches = set(self.adjacency[current_switch].keys())-set(path)
                neighbor_switches = list(neighbor_switches)
                if(len(neighbor_switches)==0):
                    path.clear()
                    current_switch = self.src
                    path.append(current_switch)
                else:
                    current_switch = self.GetNextSwitch(neighbor_switches, current_switch)
                    path.append(current_switch)
            self.colony[i].path = copy.deepcopy(path)
            self.colony[i].fitness = self.Evaluate(self.colony[i].path)
            self.colony[i].delta = self.Q/self.colony[i].fitness

    def GetNextSwitch(self, neighbor_switches, current_switch):
        summ = 0
        for sw in neighbor_switches:
            x = self.pheromone[current_switch][sw]
            y = 1/(self.weight_map[current_switch][sw])
            z = pow(x,self.a)*pow(y,self.b)
            summ+=z
        prob = []
        sw_max = 1
        z_max = 0
        for sw in neighbor_switches:
            x = self.pheromone[current_switch][sw]
            y = 1/(self.weight_map[current_switch][sw])
            z = pow(x,self.a)*pow(y,self.b)
            prob.append(z/summ)
            z2 = x*pow(y,self.b)
            if(z2>z_max):
                z_max = z2
                sw_max = sw
        p = np.random.rand()
        if(p <= self.p0):
            next_switch= sw_max
        else:
            sw = np.random.choice(neighbor_switches,p=prob)
            next_switch= sw
            # update local
            self.pheromone[current_switch][next_switch]=self.pheromone[current_switch][next_switch]*(1-self.p)+self.p*self.t0
            self.pheromone[next_switch][current_switch]=self.pheromone[next_switch][current_switch]*(1-self.p)+self.p*self.t0
        return next_switch

    def Evaluate(self,path):
        calculatedFitness = 0
        for i in range(len(path) - 1):
            p1 = path[i]
            p2 = path[i + 1]
            calculatedFitness += self.weight_map[p1][p2]
        return calculatedFitness
    
    def UpdatePheromone(self):
        # update global
        self.colony.sort(key=lambda x: x.fitness)
        for j in range(len(self.colony[0].path) - 1):
            p1 = self.colony[0].path[j]
            p2 = self.colony[0].path[j + 1]
            self.pheromone[p1][p2] = (1-self.p)*self.pheromone[p1][p2] + self.p*self.colony[0].delta
            self.pheromone[p2][p1] = (1-self.p)*self.pheromone[p2][p1] + self.p*self.colony[0].delta
     
    def MemorizeCondidates(self):
        condidate = []
        k=0
        for i in range(len(self.colony)):
            dk_3 = False
            for ant in condidate:
                if(tuple(ant.path)==tuple(self.colony[i].path)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                condidate.append(copy.deepcopy(self.colony[i]))
                k=k+1
            if(k==self.K_paths):
                break
        self.condidates.extend(copy.deepcopy(condidate))

    def GetBest(self):
        self.condidates.sort(key=lambda x: x.fitness)
        self.best.clear()
        k=0
        for i in range(len(self.condidates)):
            dk_3 = False
            for ant in self.best:
                if(tuple(ant.path)==tuple(self.condidates[i].path)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                self.best.append(copy.deepcopy(self.condidates[i]))
                k=k+1
            if(k==self.K_paths):
                break
        file1 = open('../wires.txt','r')
        Lines = file1.readlines()
        count = 0
        for line in Lines:
            if(line.strip()[0] == "A" or line.strip()[0] == "G"):
                count += 1
        file1.close()
        f1 = open("../wires.txt","a")
        if(count==3):
            f1.truncate(0)
        stt_0 = "ACS"+"\n"
        f1.write(stt_0)
        for i in range(len(self.best)):
            stt = ",".join(str(self.weight_map[self.best[i].path[x]][self.best[i].path[x+1]]) for x in range(len(self.best[i].path) - 1))
            stt= stt+"\n"
            f1.write(stt)
        f1.close()
        
    def Do(self):
        for i in range(self.Max):
            self.CreatePath()
            self.UpdatePheromone()
            self.MemorizeCondidates()
        self.GetBest()