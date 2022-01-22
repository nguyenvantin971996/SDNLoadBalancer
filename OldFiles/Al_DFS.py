MAX_PATHS  = 1
class DFS(object):
    def __init__(self, adjacency):
        self.adjacency = adjacency
        self.weight_map={}
    def get_paths(self, src, dst):
        if src == dst:
            # host target is on the same switch
            return [[src]]
        paths = []
        stack = [(src, [src])]
        while stack:
            (node, path) = stack.pop()
            for next in set(self.adjacency[node].keys()) - set(path):
                if next is dst:
                    paths.append(path + [next])
                else:
                    stack.append((next, path + [next]))
        print ("Available paths from ", src, " to ", dst, " : ", paths)
        return paths
    def get_path_cost(self, path):
        cost = 0
        temp = 0
        with open('metric_data_2.txt') as f:
            for line in f:
                strt = line
                strt2 = strt.split(':')
                my_result = list(map(int, strt2[0].split(',')))
                if (temp!=my_result[0]):
                    self.weight_map[my_result[0]]={}
                self.weight_map[my_result[0]][my_result[1]] = int(strt2[1])
                temp = my_result[0]
        for i in range(len(path) - 1):
            cost += self.weight_map[path[i]][path[i+1]]
        return cost
    def get_optimal_paths(self, src, dst):
        paths = self.get_paths(src, dst)
        paths_count = len(paths) if len(paths) < MAX_PATHS else MAX_PATHS
        return sorted(paths, key=lambda x: self.get_path_cost(x))[0:(paths_count)]
