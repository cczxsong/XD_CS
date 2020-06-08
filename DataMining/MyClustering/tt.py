from scipy.cluster.hierarchy import dendrogram, linkage, fcluster
from matplotlib import pyplot as plt
import numpy as np
# import igraph
import csv
from scipy.spatial.distance import pdist

# X = [[1, 2], [3, 2], [4, 4], [1, 2], [1, 3]]
X = [[1, 0, 1],
     [0, 1, 0],
     [1, 0, 1]]
# Z = linkage(X, 'ward')
dd = pdist(X, lambda u, v: ((u)).sum())
print dd


# print Z
# x = [[0, 3, 0, 2], [4, 5, 1.15470054, 3.], [1., 2., 2.23606798, 2.], [6., 7., 4.00832467, 5.]]

# Z = np.array(x)

# f = fcluster(Z, 4, 'distance')
# fig = plt.figure(figsize=(5, 3))
# dn = dendrogram(Z)
# plt.show()

# def gml2csv(gmlfile):
# """
# This function is used to convert a gml file into csv format.
# The graph information included in the gml file will be stored in the csv
# file as edges with the format 'vertex1 vertex2\n'
# gmlfile: The name of the gml file. Path and postfix should be included.
# """
#     g = igraph.Graph.Read_GML(gmlfile)
#     newfile = open('new.csv', 'wb')
#     writer = csv.writer(newfile, dialect = 'excel')
#     for line in g.get_edgelist():
#         writer.writerow(line)
#
# gml2csv("karate.gml")

# dict = {0: [[1, 2]], 1: [[2, 3]], 2: [[3, 4], [5, 6]]}
#
# xx= list(dict.keys())[list(dict.values()).index([[2, 3]])]
# print xx
def hier_cluster_main(self, result, dict):
    min_dis = self.min_distance(result[0], result[1])

    index1 = 0
    index2 = 1

    for i in range(len(result)):
        for j in range(i + 1, len(result)):
            dis_temp = self.min_distance(result[i], result[j])
            if dis_temp < min_dis:
                min_dis = dis_temp

                index1 = i
                index2 = j

    Metrix1 = list(dict.keys())[list(dict.values()).index(result[index1])]
    Metrix2 = list(dict.keys())[list(dict.values()).index(result[index2])]
    distance = min_dis

    result[index1].extend(result[index2])
    result.pop(index2)

    dict[dict.__len__()] = copy.deepcopy(result)[index1]

    num = len(dict[dict.__len__() - 1])

    return result, dict, Metrix1, Metrix2, distance, num


def plot_(self, Z):
    plt.figure(figsize=(10, 8))
    dendrogram(Z)
    plt.show()
