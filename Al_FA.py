import numpy as np
import random
import math
import copy

class Genome(object):
    def __init__(self):
        self.chromosomes = []
        self.code = []
        self.fitness = float('inf')
        self.fitness_vector = 0
        self.counter = 0
        self.prob = 0

class FA:

    def __init__(self,adjacency, switches, src, dst, N, generation, MAX_PATHS):
        self.adjacency = adjacency
        self.switches = switches
        self.src= src
        self.dst = dst
        self.weight_map= self.get_weight_map()
        self.N = N
        self.generation = generation
        self.MAX_PATHS = MAX_PATHS
        self.population = [self.CreateGenome() for i in range(self.N)]
        self.limit = int(N*len(switches)/2)
        self.bests = []
        self.best = []
    
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
        newGenome.fitness = self.Evaluate(newGenome.chromosomes)
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

    def initialization_phase(self):
        for i in range(self.N):
            mn = min(self.population[i].code)
            mx = max(self.population[i].code)
            self.population[i].code.clear()
            chromosomes=[]
            code = []
            while(len(chromosomes)==0):
                code.clear()
                chromosomes.clear()
                code = copy.deepcopy([(mn+np.random.rand()*(mx-mn)) for i in range(len(self.switches))])
                chromosomes = copy.deepcopy(self.Decode(code))
            self.population[i].code = copy.deepcopy(code)
            self.population[i].chromosomes = copy.deepcopy(chromosomes)
            self.population[i].fitness = self.Evaluate(self.population[i].chromosomes)
    
    def employeed_phase(self):
        population = copy.deepcopy(self.population)
        for i in range(self.N):
            r = list(range(0,i)) + list(range(i+1,self.N))
            coceg = random.choice(r)
            d = np.random.randint(len(self.switches)-1)
            genome = copy.deepcopy(self.population[i])
            code =[]
            chromosomes = []
            while(len(chromosomes)==0):
                code.clear()
                chromosomes.clear()
                fi = random.uniform(-1,1)
                code =[]
                chromosomes = []
                for ii in range(len(self.switches)):
                    if(ii==d):
                        code.append(genome.code[ii]+fi*(genome.code[ii]-self.population[coceg].code[ii]))
                    else:
                        code.append(genome.code[ii])
                mn = min(code)
                mx = max(code)
                for ii in range(len(self.switches)):
                    code[ii] = -1+2*(code[ii]-mn)/(mx-mn)
                chromosomes = copy.deepcopy(self.Decode(code))
            genome.code = copy.deepcopy(code)
            genome.chromosomes = copy.deepcopy(chromosomes)
            genome.fitness = self.Evaluate(genome.chromosomes)
            if(genome.fitness<population[i].fitness):
                genome.counter = 0
                population[i] = copy.deepcopy(genome)
            else:
                population[i].counter+=1
        self.population=copy.deepcopy(population)

    def onlooked_phase(self):
        for i in range(self.N):
            self.population[i].fitness_vector = 1/self.population[i].fitness
        sum = 0
        for i in range(self.N):
            sum+=self.population[i].fitness_vector
        prob=[]
        for i in range(self.N):
            self.population[i].prob=self.population[i].fitness_vector/sum
        for i in range(self.N):
            prob.append(self.population[i].prob)
        population= copy.deepcopy(self.population)
        for i in range(self.N):
            index_solution = np.random.choice(list(range(self.N)),p=prob)
            r = list(range(0,index_solution)) + list(range(index_solution+1,self.N))
            coceg = random.choice(r)
            d = np.random.randint(len(self.switches)-1)
            genome = copy.deepcopy(self.population[index_solution])
            code =[]
            chromosomes = []
            while(len(chromosomes)==0):
                code.clear()
                chromosomes.clear()
                fi = random.uniform(-1,1)
                code =[]
                chromosomes = []
                for ii in range(len(self.switches)):
                    if(ii==d):
                        code.append(genome.code[ii]+fi*(genome.code[ii]-self.population[coceg].code[ii]))
                    else:
                        code.append(genome.code[ii])
                mn = min(code)
                mx = max(code)
                for ii in range(len(self.switches)):
                    code[ii] = -1+2*(code[ii]-mn)/(mx-mn)
                chromosomes = copy.deepcopy(self.Decode(code))
            genome.code = copy.deepcopy(code)
            genome.chromosomes = copy.deepcopy(chromosomes)
            genome.fitness = self.Evaluate(genome.chromosomes)
            if(genome.fitness<population[index_solution].fitness):
                genome.counter = 0
                population[index_solution] = copy.deepcopy(genome)
            else:
                population[index_solution].counter+=1
        self.population=copy.deepcopy(population)

    def scout_phase(self):
        for i in range(self.N):
            if self.population[i].counter > self.limit:
                mn = min(self.population[i].code)
                mx = max(self.population[i].code)
                self.population[i].code.clear()
                chromosomes=[]
                code = []
                while(len(chromosomes)==0):
                    code.clear()
                    chromosomes.clear()
                    code = copy.deepcopy([(mn+np.random.rand()*(mx-mn)) for i in range(len(self.switches))])
                    chromosomes = copy.deepcopy(self.Decode(code))
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
        self.initialization_phase()
        for i in range(self.generation):
            self.employeed_phase()
            self.onlooked_phase()
            self.scout_phase()
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