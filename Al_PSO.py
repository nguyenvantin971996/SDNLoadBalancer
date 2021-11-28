import numpy as np
import random
import math
import copy

class Genome(object):
    def __init__(self):
        self.chromosomes = []
        self.code = []
        self.velocity = []
        self.fitness = float('inf')
        self.best_local_code = []
        self.best_local_fitness = 0


class PSO:

    def __init__(self,adjacency, switches, src, dst, N, generation, MAX_PATHS, w, c1, c2):
        self.adjacency = adjacency
        self.switches = switches
        self.src = src
        self.dst = dst
        self.weight_map= self.get_weight_map()
        self.N = N
        self.generation = generation
        self.MAX_PATHS = MAX_PATHS
        self.population = [self.CreateGenome() for i in range(self.N)]
        self.bests = []
        self.best = []
        self.w = w
        self.c1 = c1
        self.c2 = c2
        self.best_global_genome = self.CreateGenome()
    
    def get_weight_map(self):
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
        chromosomes=[]
        code = []
        while(len(chromosomes)==0):
            code.clear()
            chromosomes.clear()
            code = copy.deepcopy([random.uniform(-1,1) for i in range(len(self.switches))])
            chromosomes = copy.deepcopy(self.Decode(code))
        newGenome.code = copy.deepcopy(code)
        newGenome.chromosomes = copy.deepcopy(chromosomes)
        newGenome.velocity = [ i*0.1 for i in newGenome.code]
        newGenome.fitness = self.Evaluate(newGenome.chromosomes)
        newGenome.best_local_code= [0 for i in range(len(self.switches))]
        newGenome.best_local_fitness = newGenome.fitness
        return newGenome
    
    def Decode(self,code):
        chromosomes = []
        chromosomes.append(self.src)
        current_switch = self.src
        while(current_switch!=self.dst):
            neighbor_switches = set(self.adjacency[current_switch].keys())-set(chromosomes)
            neighbor_switches = list(neighbor_switches)
            if(len(neighbor_switches)==0):
                chromosomes.clear()
                break
            switch_min = 1
            min = float('inf')
            for switch in neighbor_switches:
                if(code[switch-1]*self.weight_map[current_switch][switch] <= min):
                    min = code[switch-1]*self.weight_map[current_switch][switch]
                    switch_min = switch
            current_switch = switch_min
            chromosomes.append(current_switch)
        return chromosomes

    def Evaluate(self,chromosomes):
        calculatedFitness = 0
        for i in range(len(chromosomes) - 1):
            p1 = chromosomes[i]
            p2 = chromosomes[i + 1]
            calculatedFitness += self.weight_map[p1][p2]
        return calculatedFitness

    def Find_best(self):
        self.population.sort(key=lambda x: x.fitness)
        if(self.population[0].fitness<=self.best_global_genome.fitness):
            self.best_global_genome = copy.deepcopy(self.population[0])
        for i in range(self.N):
            if(self.population[i].fitness<=self.population[i].best_local_fitness):
                self.population[i].best_local_code = copy.deepcopy(self.population[i].code)
                self.population[i].best_local_fitness = self.population[i].fitness

    def Update(self):
        for i in range(self.N):
            velocity = copy.deepcopy(self.population[i].velocity)
            code = copy.deepcopy(self.population[i].code)
            chromosomes = []
            while(len(chromosomes)==0):
                for j in range(len(self.switches)):
                    r1 = np.random.rand()
                    r2 = np.random.rand()
                    velocity[j] = self.w*self.population[i].velocity[j] + self.c1*r1*(self.population[i].best_local_code[j]-self.population[i].code[j])+self.c2*r2*(self.best_global_genome.code[j]-self.population[i].code[j])
                for j in range(len(self.switches)):
                    code[j] = self.population[i].code[j] + velocity[j]
                mn = min(code)
                mx = max(code)
                for ii in range(len(self.switches)):
                    code[ii] = -1+2*(code[ii]-mn)/(mx-mn)
                chromosomes = copy.deepcopy(self.Decode(code))
            self.population[i].velocity = copy.deepcopy(velocity)
            self.population[i].code = copy.deepcopy(code)
            self.population[i].chromosomes = copy.deepcopy(chromosomes)
            self.population[i].fitness = self.Evaluate(self.population[i].chromosomes)

    def Memorize_best(self):
        self.population.sort(key=lambda x: x.fitness)
        self.bests.append(copy.deepcopy(self.population[0]))
        k=1
        for i in range(1,len(self.population)):
            dk_3 = False
            for genome in self.bests:
                if(tuple(genome.chromosomes)==tuple(self.population[i].chromosomes)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                self.bests.append(copy.deepcopy(self.population[i]))
                k=k+1
            if(k==self.MAX_PATHS):
                break
    
    def Do(self):
        for i in range(self.generation):
            self.Find_best()
            self.Update()
            self.Memorize_best()
        self.bests.sort(key=lambda x: x.fitness)
        self.best.append(copy.deepcopy(self.bests[0]))
        k=1
        for i in range(1,len(self.bests)):
            dk_3 = False
            for genome in self.best:
                if(tuple(genome.chromosomes)==tuple(self.bests[i].chromosomes)):
                    dk_3 = True
                    break
            if(dk_3!=True):
                self.best.append(copy.deepcopy(self.bests[i]))
                k=k+1
            if(k==self.MAX_PATHS):
                break
        f1=open("wires.txt","w")
        f1.truncate(0)
        for i in range(self.MAX_PATHS):
            stt = ",".join(str(self.weight_map[self.best[i].chromosomes[x]][self.best[i].chromosomes[x+1]]) for x in range(len(self.best[i].chromosomes) - 1))
            stt= stt+"\n"
            f1.write(stt)
        f1.close()
# switches=[1,2,3,4,5]
# adjacency={
# 	1:{2:0,3:0,4:0},
# 	2:{1:0,4:0,5:0},
# 	3:{1:0,4:0,5:0},
# 	4:{1:0,2:0,3:0,5:0},
# 	5:{2:0,3:0,4:0}
# }
# alg = ABC(adjacency,switches,1,5,50,10,2)
# alg.Do()
# print(alg.best)