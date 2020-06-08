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




def create_C1(data_set):
    C1 = set()
    for t in data_set:
        for item in t:
            item_set = frozenset([item])
            C1.add(item_set)
    return C1


def is_apriori(Ck_item, Lksub1):

    for item in Ck_item:
        sub_Ck = Ck_item - frozenset([item])
        if sub_Ck not in Lksub1:
            return False
    return True


def create_Ck(Lksub1, k):

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

    Lk = set()
    item_count = {}
    for t in data_set:
        for item in Ck:
            if item.issubset(t):
                if item not in item_count:
                    item_count[item] = 1
                else:
                    item_count[item] += 1
    t_num = float(len(data_set))
    for item in item_count:
        if (item_count[item] / t_num) >= min_support:
            Lk.add(item)        # 满足最小支持度的项集add进频繁项集Lk中
            support_data[item] = item_count[item] / t_num
    return Lk


def generate_L(data_set, k, min_support):

    support_data = {}
    C1 = create_C1(data_set)        # 生成C1
    L1 = generate_Lk_by_Ck(data_set, C1, min_support, support_data)     # 生成L1
    Lksub1 = L1.copy()
    L = []
    L.append(Lksub1)
    for i in range(2, k + 1):
        Ci = create_Ck(Lksub1, i)
        Li = generate_Lk_by_Ck(data_set, Ci, min_support, support_data)
        Lksub1 = Li.copy()
        L.append(Lksub1)
    return L, support_data


def generate_big_rules(L, support_data, min_conf):

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
