from DijkstraAlgorithm import DijkstraAlgorithm
import copy
class Path(object):
    def __init__(self):
        self.path_vertices = []
        self.dictance = 0

class YenAlgorithm(object):

    def __init__(self, vertices, src, dst, K_paths, Metric):
        self._vertices = vertices
        self._source_vertex = src
        self._destination_vertex = dst
        self.K_paths = K_paths
        self.Metric = Metric
        self._weight_map = self.GetWeightMap()

    def GetWeightMap(self):
        weight_map={}
        temp = []
        with open('metric_data.txt') as f:
            for line in f:
                strt = line
                strt2 = strt.split(':')
                strt3 = list(map(int, strt2[1].split(',')))
                my_result = list(map(int, strt2[0].split(',')))
                if (my_result[0] not in temp):
                    weight_map[my_result[0]]={}
                    temp.append(my_result[0])
                if(self.Metric==1):
                    weight_map[my_result[0]][my_result[1]] = int(round(100/int(strt3[1])))
                elif(self.Metric==2):
                    weight_map[my_result[0]][my_result[1]] = int(strt3[0])
                elif(self.Metric==3):
                    weight_map[my_result[0]][my_result[1]] = int(round(100/int(strt3[1]))) + 1*int(strt3[0])
        return weight_map

    def compute_shortest_paths(self):
        paths =[]
        p0 = Path()
        alg = DijkstraAlgorithm(self._weight_map,self._vertices)
        p0.path_vertices = alg.compute_shortest_path(self._source_vertex,self._destination_vertex)
        for m in range(len(p0.path_vertices)-1):
            p0.dictance += self._weight_map[p0.path_vertices[m]][p0.path_vertices[m+1]]
        paths.append(p0)
        B = []
        for i in range(1,self.K_paths):
            for j in range(len(paths[i-1].path_vertices)-1):
                path = Path()
                weight = copy.deepcopy(self._weight_map)
                rootPath = paths[i-1].path_vertices[:j+1]
                spurNode = paths[i-1].path_vertices[j]
                for m in range(i):
                    if (rootPath == paths[m].path_vertices[:j+1]):
                        weight[paths[m].path_vertices[j]][paths[m].path_vertices[j+1]] = 9999999999
                        weight[paths[m].path_vertices[j+1]][paths[m].path_vertices[j]] = 9999999999
                for m in range(j):
                    for node_2 in weight[rootPath[m]].keys():
                        weight[rootPath[m]][node_2] = 9999999999
                        weight[node_2][rootPath[m]] = 9999999999
                alg_d = DijkstraAlgorithm(weight,self._vertices)
                spurpath = alg_d.compute_shortest_path(spurNode,self._destination_vertex)
                rootPath.pop()
                rootPath.extend(spurpath)
                path.path_vertices = copy.deepcopy(rootPath)
                for m in range(len(path.path_vertices)-1):
                    path.dictance += self._weight_map[path.path_vertices[m]][path.path_vertices[m+1]]
                dk = True
                for path_b in B:
                    if(path_b.path_vertices == path.path_vertices):
                        dk = False
                check = 0
                for m in range(len(spurpath)-1):
                    check += weight[spurpath[m]][spurpath[m+1]]
                if(check>=9999999999):
                    dk = False
                if(dk):
                    B.append(copy.deepcopy(path))
            B.sort(key=lambda x: x.dictance)
            paths.append(copy.deepcopy(B[0]))
            B.pop(0)
        return paths