# encoding:utf-8

def prepare_data(file):
    CQA = ["Class-Name", "handicapped-infants", "water-project-cost-sharing", "adoption-of-the-budget-resolution",
           "physician-fee-freeze", "el-salvador-aid", "religious-groups-in-schools", "anti-satellite-test-ban",
           "aid-to-nicaraguan-contras", "mx-missile", "immigration", "synfuels-corporation-cutback",
           "education-spending",
           "superfund-right-to-sue", "crime", "duty-free-exports", "export-administration-act-south-africa"]
    dataset = [x.strip().split(',') for x in open(file)]
    new_dataset = []
    for data in dataset:
        new_data = set()
        for i, x in enumerate(data):
            new_data.add(CQA[i] + "_" + x)
        # print new_data
        new_dataset.append(new_data)
    f = open('new-house-votes.data', 'w')
    for t in new_dataset:
        f.write(','.join(str(x) for x in t) + '\n')
    f.close()


def load_data_set():
    """
    Load a sample data set (From Data Mining: Concepts and Techniques, 3th Edition)
    Returns:
        A data set: A list of transactions. Each transaction contains several items.
    加载一个示例集合
    Returns:
        A data set: 一个购物列表，每个项中有不同的商品item
    """
    data_set = [['l1', 'l2', 'l5'], ['l2', 'l4'], ['l2', 'l3'],
                ['l1', 'l2', 'l4'], ['l1', 'l3'], ['l2', 'l3'],
                ['l1', 'l3'], ['l1', 'l2', 'l3', 'l5'], ['l1', 'l2', 'l3']]
    return data_set


def create_C1(data_set):
    """
    扫描数据集，创建元素个数为1的项集C1，作为频繁项集的候选项集C1
    Create frequent candidate 1-itemset C1 by scaning data set.
    Args:
        data_set: A list of transactions. Each transaction contains several items.
    Returns:
        C1: A set which contains all frequent candidate 1-itemsets
    """
    C1 = set()
    for t in data_set:
        for item in t:
            item_set = frozenset([item])
            """
                       由于要使用字典（support_data）记录项集的支持度，需要用项集作为key，
                       而可变集合无法作为字典的key，因此在合适时机应将项集转为固定集合frozenset。
                       或者另一种用法：
                       for item in t:
                           C1.append([item])
                       C1.sort()
                       return map(frozenset,C1)
            """
            C1.add(item_set)
    return C1


def is_apriori(Ck_item, Lksub1):
    """
    进行剪枝，如果满足APriori，即满足支持度，返回True
    否则返回False，删除

    Judge whether a frequent candidate k-itemset satisfy Apriori property.
    Args:
        Ck_item: a frequent candidate k-itemset in Ck which contains all frequent
                 candidate k-itemsets.
        Lksub1: Lk-1, a set which contains all frequent candidate (k-1)-itemsets.
    Returns:
        True: satisfying Apriori property.
        False: Not satisfying Apriori property.
    """
    for item in Ck_item:
        sub_Ck = Ck_item - frozenset([item])
        if sub_Ck not in Lksub1:
            return False
    return True


def create_Ck(Lksub1, k):
    """
        由Lk-1生成Ck
        具体实现方法是在Lk-1中，对所有两个项集之间只有最后一项item不同的项集的交集
    """
    """
    Create Ck, a set which contains all all frequent candidate k-itemsets
    by Lk-1's own connection operation.
    Args:
        Lksub1: Lk-1, a set which contains all frequent candidate (k-1)-itemsets.
        k: the item number of a frequent itemset.
    Return:
        Ck: a set which contains all all frequent candidate k-itemsets.
    """
    Ck = set()
    len_Lksub1 = len(Lksub1)
    list_Lksub1 = list(Lksub1)
    for i in range(len_Lksub1):
        for j in range(1, len_Lksub1):
            l1 = list(list_Lksub1[i])
            l2 = list(list_Lksub1[j])
            l1.sort()
            l2.sort()
            if l1[0:k - 2] == l2[0:k - 2]:
                Ck_item = list_Lksub1[i] | list_Lksub1[j]
                # pruning
                if is_apriori(Ck_item, Lksub1):
                    Ck.add(Ck_item)
    return Ck


def generate_Lk_by_Ck(data_set, Ck, min_support, support_data):
    """
        由候选频繁k项集Ck生成频繁k项集Lk
        主要内容是对Ck中的每个项集计算支持度，去掉不满足最低支持度的项集
        返回Lk，记录support_data
        """
    """
    Generate Lk by executing a delete policy from Ck.
    Args:
        data_set: A list of transactions. Each transaction contains several items.
        Ck: A set which contains all all frequent candidate k-itemsets.
        min_support: The minimum support.
        support_data: A dictionary. The key is frequent itemset and the value is support.
    Returns:
        Lk: A set which contains all all frequent k-itemsets.
    """
    Lk = set()
    item_count = {}
    for t in data_set:  # 扫描所有商品，计算候选频繁项集C中项集的支持度，t为订单
        for item in Ck:  # item为C中的项集
            if item.issubset(t):  # 如果C中的项集是t订单的子集
                if item not in item_count:  # 如果item_count中还没有这个项集，计数为1
                    item_count[item] = 1
                else:  # 如果item_count中已经有了这个项集，计数加1
                    item_count[item] += 1
    t_num = float(len(data_set))  # t_num，订单总数
    for item in item_count:  # item_count中已经有了所有的候选项集，计算支持度
        if (item_count[item] / t_num) >= min_support:
            Lk.add(item)  # 满足最小支持度的项集add进频繁项集Lk中
            support_data[item] = item_count[item] / t_num  # 记录支持度，返回Lk
    return Lk


def generate_L(data_set, k, min_support):
    """
        生成频繁集Lk，通过调用generate_Lk_by_Ck
        从C1开始共进行k轮迭代，将每次生成的Lk都append到L中，同时记录支持度support_data
        """
    """
    Generate all frequent itemsets.
    Args:
        data_set: A list of transactions. Each transaction contains several items.
        k: Maximum number of items for all frequent itemsets.
        min_support: The minimum support.
    Returns:
        L: The list of Lk.
        support_data: A dictionary. The key is frequent itemset and the value is support.
    """
    support_data = {}
    C1 = create_C1(data_set)  # 生成C1
    L1 = generate_Lk_by_Ck(data_set, C1, min_support, support_data)  # 由C1生成L1，调用generate_Lk_by_Ck函数
    Lksub1 = L1.copy()
    L = []
    L.append(Lksub1)
    for i in range(2, k + 1):  # 由k已知进行重复迭代
        Ci = create_Ck(Lksub1, i)  # 由Lk生成Lk+1，调用create_Ck函数
        Li = generate_Lk_by_Ck(data_set, Ci, min_support, support_data)
        Lksub1 = Li.copy()
        L.append(Lksub1)
    return L, support_data


def generate_big_rules(L, support_data, min_conf):
    """
    Generate big rules from frequent itemsets.
    Args:
        L: The list of Lk.
        support_data: A dictionary. The key is frequent itemset and the value is support.
        min_conf: Minimal confidence.
    Returns:
        big_rule_list: A list which contains all big rules. Each big rule is represented
                       as a 3-tuple.
    """
    big_rule_list = []
    sub_set_list = []
    for i in range(0, len(L)):
        for freq_set in L[i]:
            for sub_set in sub_set_list:
                if sub_set.issubset(freq_set):
                    conf = support_data[freq_set] / support_data[freq_set - sub_set]
                    big_rule = (freq_set - sub_set, sub_set, conf)
                    if conf >= min_conf and big_rule not in big_rule_list:
                        # print freq_set-sub_set, " => ", sub_set, "conf: ", conf
                        big_rule_list.append(big_rule)
            sub_set_list.append(freq_set)
    return big_rule_list


if __name__ == "__main__":

    print "=" * 50
    prepare_data("./house-votes-84.data")
    # data_set = load_data_set()
    # print data_set
    data_set = [(s.strip().split(',')) for s in open('new-house-votes.data')]

    L, support_data = generate_L(data_set, k=3, min_support=0.3)

    big_rules_list = generate_big_rules(L, support_data, min_conf=0.9)

    print 'Big Rules'

    print 'Name_democrat rules'
    print
    d_num = 0
    r_num = 0

    for item in big_rules_list:
        if "Class-Name_democrat" in item[0]:
            d_num = d_num + 1
            for i in item[0]:
                print i,
            print "==>",
            for j in item[1]:
                print j,
            print "conf: ", item[2]
    print d_num, 'rules'

    print '=' * 60
    print 'Name_republican rules'
    print
    for item in big_rules_list:
        if "Class-Name_republican" in item[0]:
            r_num = r_num + 1
            for i in item[0]:
                print i,
            print "==>",
            for j in item[1]:
                print j,
            print "conf: ", item[2]
    print r_num, 'rules'
