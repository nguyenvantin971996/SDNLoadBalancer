import numpy as np
import random
import math
import copy

class Genome(object):
    def __init__(self):
        self.chromosomes = []
        self.fitness = float('inf')

class GA:

    def __init__(self,adjacency, switches, src, dst, N, iterations, Pc, Pm):
        self.adjacency = adjacency
        self.switches = switches
        self.src= src
        self.dst = dst
        self.weight_map= self.GetWeightMap()
        self.N = N
        self.iterations = iterations
        self.Pm = Pm
        self.Pc = Pc
        self.population = [self.CreateGenome() for i in range(self.N)]
        self.condidates = []
        self.best = []
    
    def GetWeightMap(self):
        weight_map={}
        temp = 0
        with open('metric_data_2.txt') as f:
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
        newGenome.chromosomes.append(self.src)
        current_switch = self.src
        while(current_switch!=self.dst):
            neighbor_switches = set(self.adjacency[current_switch].keys())-set(newGenome.chromosomes)
            neighbor_switches = list(neighbor_switches)
            if(len(neighbor_switches)==0):
                newGenome.chromosomes.clear()
                current_switch = self.src
                newGenome.chromosomes.append(self.src)
            else:
                next_switch = random.choice(neighbor_switches)
                newGenome.chromosomes.append(next_switch)
                current_switch = next_switch
        newGenome.fitness = self.Evaluate(newGenome.chromosomes)
        return newGenome

    def Evaluate(self,chromosomes):
        calculatedFitness = 0
        for i in range(len(chromosomes) - 1):
            p1 = chromosomes[i]
            p2 = chromosomes[i + 1]
            calculatedFitness += self.weight_map[p1][p2]
        return calculatedFitness
    
    def Crossover(self):
        for i in range(self.N):
            if random.uniform(0,1) < self.Pc:
                father = random.randint(0,self.N-1)
                mother = random.randint(0,self.N-1)
                parents_1 = copy.deepcopy(self.population[father])
                parents_2 = copy.deepcopy(self.population[mother])
                dk = False
                for i in range(1,len(parents_1.chromosomes)-1):
                    for j in range(1,len(parents_2.chromosomes)-1):
                        if(parents_1.chromosomes[i]==parents_2.chromosomes[j]):
                            tail_1 = copy.deepcopy(parents_1.chromosomes[i+1:])
                            tail_2 = copy.deepcopy(parents_2.chromosomes[j+1:])
                            del parents_1.chromosomes[i+1:]
                            del parents_2.chromosomes[j+1:]
                            parents_1.chromosomes.extend(tail_2)
                            parents_2.chromosomes.extend(tail_1)
                            dk = True
                            break
                    if(dk==True):
                        break
                dk_1 = False
                for i in range(1,len(parents_1.chromosomes)-2):
                    for j in range(i+1,len(parents_1.chromosomes)-1):
                        if(parents_1.chromosomes[i]==parents_1.chromosomes[j]):
                            del parents_1.chromosomes[i+1:j+1]
                            dk_1 = True
                            break
                    if(dk_1==True):
                        break
                dk_2 = False
                for i in range(1,len(parents_2.chromosomes)-2):
                    for j in range(i+1,len(parents_2.chromosomes)-1):
                        if(parents_2.chromosomes[i]==parents_2.chromosomes[j]):
                            del parents_2.chromosomes[i+1:j+1]
                            dk_2 = True
                            break
                    if(dk_2==True):
                        break
                parents_1.fitness = self.Evaluate(parents_1.chromosomes)
                parents_2.fitness = self.Evaluate(parents_2.chromosomes)
                self.population.append(copy.deepcopy(parents_1))
                self.population.append(copy.deepcopy(parents_2))
    
    def Mutation(self):
        for i in range(self.N):
            if random.uniform(0,1) < self.Pm:
                origin = random.randint(0,self.N-1)
                parents = copy.deepcopy(self.population[origin]) 
                ls = list(range(1,len(parents.chromosomes)-1))
                point_mutation = random.choice(ls)
                current_switch = parents.chromosomes[point_mutation]
                del parents.chromosomes[point_mutation+1:]
                while(current_switch!=self.dst):
                    neighbor_switches = set(self.adjacency[current_switch].keys())
                    neighbor_switches = list(neighbor_switches)
                    next_switch = random.choice(neighbor_switches)
                    parents.chromosomes.append(next_switch)
                    current_switch = next_switch
                parents.fitness = self.Evaluate(parents.chromosomes)
                self.population.append(copy.deepcopy(parents))
                
    def Selection(self):
        selected_population=[]
        for i in range(self.N):
            k_1 = random.randint(0,len(self.population)-1)
            k_2 = random.randint(0,len(self.population)-1)
            if(self.population[k_1].fitness<self.population[k_2].fitness):
                selected_population.append(self.population[k_1])
            else:
                selected_population.append(self.population[k_2])
        self.population = copy.deepcopy(selected_population)
    
    def MemorizeCondidates(self):
        self.population.sort(key=lambda x: x.fitness)
        for i in range(len(self.population)):
            dk_3 = False
            for genome in self.condidates:
                if(tuple(genome.chromosomes)==tuple(self.population[i].chromosomes)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                if(self.population[i].fitness < self.population[0].fitness/0.7):
                    self.condidates.append(copy.deepcopy(self.population[i]))
    
    def GetBest(self):
        self.condidates.sort(key=lambda x: x.fitness)
        for i in range(len(self.condidates)):
            dk_3 = False
            for genome in self.best:
                if(tuple(genome.chromosomes)==tuple(self.condidates[i].chromosomes)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                if(self.condidates[i].fitness < self.condidates[0].fitness/0.7):
                    self.best.append(copy.deepcopy(self.condidates[i]))
        f1=open("wires.txt","w")
        f1.truncate(0)
        for i in range(len(self.best)):
            stt = ",".join(str(self.weight_map[self.best[i].chromosomes[x]][self.best[i].chromosomes[x+1]]) for x in range(len(self.best[i].chromosomes) - 1))
            stt= stt+"\n"
            f1.write(stt)
        f1.close()
    
    def Do(self):
        for i in range(self.iterations):
            self.Crossover()
            self.Mutation()
            self.Selection()
            self.MemorizeCondidates()
        self.GetBest()