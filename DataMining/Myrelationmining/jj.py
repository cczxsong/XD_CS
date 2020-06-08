# -*- coding: utf-8 -*-
"""
Apriori exercise.
Created on Fri Nov 27 11:09:03 2015

@author: 90Zeng
"""


def loadDataSet():
    '''创建一个用于测试的简单的数据集'''
    return [[1, 3, 4], [2, 3, 5], [1, 2, 3, 5], [2, 5]]


def createC1(dataSet):
    '''
    构建初始候选项集的列表，即所有候选项集只包含一个元素，
    C1是大小为1的所有候选项集的集合
    '''
    C1 = []
    for transaction in dataSet:
        for item in transaction:
            if [item] not in C1:
                C1.append([item])
    C1.sort()
    return map(frozenset, C1)


def scanD(D, Ck, minSupport):
    '''
    计算Ck中的项集在数据集合D(记录或者transactions)中的支持度,
    返回满足最小支持度的项集的集合，和所有项集支持度信息的字典。
    '''
    ssCnt = {}
    for tid in D:
        # 对于每一条transaction
        for can in Ck:
            # 对于每一个候选项集can，检查是否是transaction的一部分
            # 即该候选can是否得到transaction的支持
            if can.issubset(tid):
                ssCnt[can] = ssCnt.get(can, 0) + 1
    numItems = float(len(D))
    retList = []
    supportData = {}
    for key in ssCnt:
        # 每个项集的支持度
        support = ssCnt[key] / numItems

        # 将满足最小支持度的项集，加入retList
        if support >= minSupport:
            # retList.insert(0, key)
            retList.append(key)

        # 汇总支持度数据
        supportData[key] = support
    return retList, supportData


if __name__ == '__main__':
    # 导入数据集
    myDat = loadDataSet()
    # 构建第一个候选项集列表C1
    C1 = createC1(myDat)

    # 构建集合表示的数据集 D
    D = map(set, myDat)
    # 选择出支持度不小于0.5 的项集作为频繁项集
    L, suppData = scanD(D, C1, 0.5)

    print u"频繁项集L：", L
    print u"所有候选项集的支持度信息：", suppData