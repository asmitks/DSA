#Solution for problem https://www.codechef.com/MAY20B/problems/CORUS
T = int(input())
for x in range(T):
    N,Q = [int(i) for i in input().split(" ")]
    S = input()
    dic = {}
    for i in S:
        if i not in dic.keys():
            dic[i] = 1
        else:
            dic[i] += 1
    for y in range(Q):
        C = int(input())
        waiting = 0
        for i in dic.keys():
            waiting+=max(dic[i]-C,0)
        print(waiting)
