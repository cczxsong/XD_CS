# coding=utf-8
import math
import copy
from scipy.cluster.hierarchy import dendrogram, linkage, fcluster
from matplotlib import pyplot as plt
import numpy as np


def prepare_data(file):
    a = np.zeros((35, 35), dtype=np.int)
    # print a
    G = open(file, 'r')
    G = G.read()
    W = G.replace("[", '')
    W = W.replace("]", '')

    W = filter(str.isalnum, W)
    W = W[W.find("edge"):len(W)]
    W = W.replace("edgesource", ' ')
    W = W.replace("target", ' ')
    W = W[1:len(W)]
    W = W.split(' ')
    data = []
    for i, x in enumerate(W):
        if i != len(W) - 1:
            data.append([int(W[i]), int(W[i + 1])])

    data = data[::2]
    for x in data:
        a[x[0]][x[1]] = 1
        a[x[1]][x[0]] = 1
    # print data
    # print a
    return data, a


class hcluster:
    res = []
    dict = {}
    result = []
    x = 1

    def __init__(self):
        pass

    def hier_cluster_init(self, data):

        narry = []
        for aData in data:
            self.result.append([aData])
            self.dict[self.dict.__len__()] = [aData]

        # print result,dict
        while self.result.__len__() != 1:
            self.res.append(copy.deepcopy(self.result))
            self.result, self.dict, Metrix1, Metrix2, distance, num = self.hier_cluster_main(self.result, self.dict)
            narry.append([Metrix1, Metrix2, distance, num])

        self.res.append(copy.deepcopy(self.result))

        narry = np.array(narry)
        # print self.res
        # print self.dict
        # print narry
        # print self.dict[5]
        return narry

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

    def get_distance(self, data1, data2):
        distance = 0
        for i in range(len(data1)):
            distance += pow((data1[i] - data2[i]), 2)
        return math.sqrt(distance)

    def min_distance(self, list1, list2):

        min_dis = self.get_distance(list1[0], list2[0])
        for i in range(len(list1)):
            for j in range(len(list2)):
                dis_temp = self.get_distance(list1[i], list2[j])
                if dis_temp < min_dis:
                    min_dis = dis_temp
        return min_dis * math.sqrt(len(list1))

    def plot_(self, Z):
        plt.figure(figsize=(10, 8))
        dendrogram(Z)
        plt.show()


if __name__ == "__main__":
    # data = [[1, 2], [3, 2], [4, 4], [1, 4], [1, 3]]
    data, a = prepare_data("karate.gml")
    hc = hcluster()
    Z_edge = hc.hier_cluster_init(data)
    #
    # New = open("newdata.txt", 'w+')
    # # lis = data.tolist()
    # for t in data:
    #     New.write(' '.join(str(x) for x in t) + '\n')
    #
    # New.close()

    Z_point = linkage(a, method='weighted', metric='euclidean')
    # print Z
    # x = [[0., 4., 1., 2.], [3., 5., 1.5, 3.], [1., 2., 2.23606798, 2. ], [6., 7., 2.8325939, 5.]]
    # Z = np.array(x)

    # f = fcluster(Z, 4, 'distance')
    hc.plot_(Z_point)
    hc.plot_(Z_edge)
