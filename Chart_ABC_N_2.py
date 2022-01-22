from Al_ABC import ABC

N = [25, 50, 100]
Max = 100
K_paths = 10

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
vertices = [i for i in range(1,31)]
st = "ABC_N_2:"
alg = ABC(weight_map,vertices,1,19,N[0],Max,K_paths,st)
alg.Do()
alg1 = ABC(weight_map,vertices,1,19,N[1],Max,K_paths,st)
alg1.Do()
alg2 = ABC(weight_map,vertices,1,19,N[2],Max,K_paths,st)
alg2.Do()