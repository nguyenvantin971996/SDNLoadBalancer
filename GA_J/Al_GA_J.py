import numpy as np
import random
import math
import copy
from DrawChart import BarChart

class Genome(object):
    def __init__(self):
        self.path = []
        self.fitness = float('inf')

class GA:

    def __init__(self,adjacency, switches, src, dst, N, Max, Pc, Pm, st):
        self.adjacency = adjacency
        self.switches = switches
        self.src= src
        self.dst = dst
        self.weight_map = self.GetWeightMap()
        self.N = N
        self.Max = Max
        self.Pm = Pm
        self.Pc = Pc
        self.population = [self.CreateGenome() for i in range(self.N)]
        self.condidates = []
        self.best = []
        self.st = st
    
    def GetWeightMap(self):
        weight_map={}
        temp = 0
        with open('metric_data.txt') as f:
            for line in f:
                strt = line
                strt2 = strt.split(':')
                my_result = list(map(int, strt2[0].split(',')))
                if (temp!=my_result[0]):
                    weight_map[my_result[0]]={}
                weight_map[my_result[0]][my_result[1]] = int(strt2[1])
                temp = my_result[0]
        return weight_map

    def CreateGenome(self):
        newGenome = Genome()
        newGenome.path.append(self.src)
        current_switch = self.src
        while(current_switch!=self.dst):
            neighbor_switches = set(self.adjacency[current_switch].keys())-set(newGenome.path)
            neighbor_switches = list(neighbor_switches)
            if(len(neighbor_switches)==0):
                newGenome.path.clear()
                current_switch = self.src
                newGenome.path.append(self.src)
            else:
                next_switch = random.choice(neighbor_switches)
                newGenome.path.append(next_switch)
                current_switch = next_switch
        newGenome.fitness = self.Evaluate(newGenome.path)
        return newGenome

    def Evaluate(self,path):
        calculatedFitness = 0
        for i in range(len(path) - 1):
            p1 = path[i]
            p2 = path[i + 1]
            calculatedFitness += self.weight_map[p1][p2]
        return calculatedFitness
    
    def CorrectGenome(self,genome):
        dk = False
        for i in range(1,len(genome.path)-2):
            for j in range(i+1,len(genome.path)-1):
                if(genome.path[i]==genome.path[j]):
                    del genome.path[i+1:j+1]
                    dk = True
                    break
            if(dk==True):
                break
        return genome
    
    def ExchangeGenes(self, parents_1, parents_2):
        dk = False
        for i in range(1,len(parents_1.path)-1):
            for j in range(1,len(parents_2.path)-1):
                if(parents_1.path[i]==parents_2.path[j]):
                    tail_1 = copy.deepcopy(parents_1.path[i+1:])
                    tail_2 = copy.deepcopy(parents_2.path[j+1:])
                    del parents_1.path[i+1:]
                    del parents_2.path[j+1:]
                    parents_1.path.extend(tail_2)
                    parents_2.path.extend(tail_1)
                    dk = True
                    break
            if(dk==True):
                break
        return parents_1, parents_2

    def Crossover(self):
        for i in range(self.N):
            if random.uniform(0,1) < self.Pc:
                father = random.randint(0,self.N-1)
                mother = random.randint(0,self.N-1)
                parents_1 = copy.deepcopy(self.population[father])
                parents_2 = copy.deepcopy(self.population[mother])
                child_1, child_2 = self.ExchangeGenes(parents_1, parents_2)
                child_1 = self.CorrectGenome(child_1)
                child_2  = self.CorrectGenome(child_2 )
                child_1.fitness = self.Evaluate(child_1.path)
                child_2.fitness = self.Evaluate(child_2.path)
                self.population.append(copy.deepcopy(child_1))
                self.population.append(copy.deepcopy(child_2))
    
    def Mutation(self):
        for i in range(self.N,len(self.population)):
            if random.uniform(0,1) < self.Pm:
                parents = copy.deepcopy(self.population[i]) 
                ls = list(range(1,len(parents.path)-1))
                point_mutation = random.choice(ls)
                current_switch = parents.path[point_mutation]
                del parents.path[point_mutation+1:]
                while(current_switch!=self.dst):
                    neighbor_switches = set(self.adjacency[current_switch].keys())
                    neighbor_switches = list(neighbor_switches)
                    next_switch = random.choice(neighbor_switches)
                    parents.path.append(next_switch)
                    current_switch = next_switch
                parents.fitness = self.Evaluate(parents.path)
                self.population[i]=copy.deepcopy(parents)
                
    def Selection(self):
        selected_population=[]
        for i in range(self.N):
            selected_index = np.random.randint(0,len(self.population)-1)
            for ix in np.random.randint(0,len(self.population)-1,5):
                if(self.population[ix].fitness<self.population[selected_index].fitness):
                    selected_index = ix
            selected_population.append(self.population[selected_index])
        self.population = copy.deepcopy(selected_population)
    
    def MemorizeCondidates(self):
        self.population.sort(key=lambda x: x.fitness)
        for i in range(len(self.population)):
            dk_3 = False
            for genome in self.condidates:
                if(tuple(genome.path)==tuple(self.population[i].path)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                if(self.population[i].fitness < self.population[0].fitness/0.8):
                    self.condidates.append(copy.deepcopy(self.population[i]))
    
    def GetBest(self):
        self.condidates.sort(key=lambda x: x.fitness)
        for i in range(len(self.condidates)):
            dk_3 = False
            for genome in self.best:
                if(tuple(genome.path)==tuple(self.condidates[i].path)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                if(self.condidates[i].fitness < self.condidates[0].fitness/0.8):
                    self.best.append(copy.deepcopy(self.condidates[i]))

        file1 = open('wires.txt','r')
        Lines = file1.readlines()
        count = 0
        for line in Lines:
            if(line.strip()[0] == "N"):
                count += 1
        file1.close()

        f1 = open("wires.txt","a")
        if(count==3):
            f1.truncate(0)
        stt_0 = ",".join(["N = "+str(self.N), "Max = "+str(self.Max), "Pc = "+str(self.Pc), "Pm = "+str(self.Pm)]) + "\n"
        f1.write(stt_0)
        for i in range(len(self.best)):
            stt = ",".join(str(self.weight_map[self.best[i].path[x]][self.best[i].path[x+1]]) for x in range(len(self.best[i].path) - 1))
            stt= stt+"\n"
            f1.write(stt)
        f1.close()
        
        # values = []
        # sttt = self.st+" "+ stt_0
        # for x in range(len(self.best)):
        #     values.append(self.best[x].fitness)
        # chart = BarChart(values,sttt)
        # chart.Do()
    
    def Do(self):
        for i in range(self.Max):
            self.Crossover()
            self.Mutation()
            self.Selection()
            self.MemorizeCondidates()
        self.GetBest()