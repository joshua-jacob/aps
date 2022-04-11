# https://www.codechef.com/FEB20B/problems/CHEFRAIL

linp = lambda a:list(map(int,input().split(' ')))
minp = lambda a:map(int,input().split(' '))
inp = lambda a:int(input())
MD = 1000000007
from itertools import combinations
from collections import Counter

t=inp(0)
for _ in range(t):
    n,m=minp(0)
    x=linp(0)
    y=linp(0)
    x1=list(combinations(x,2))
    y1=list(combinations(y,2))
    xsq=[i**2 for i in x]
    ysq=[i**2 for i in y]
    x2=dict(Counter(xsq))
    y2=dict(Counter(ysq))
    ans = 0
    # print('x,y',x,y)
    # print('x1,y1',x1,y1)
    # print('x2,y2',x2,y2)
    for i in x1:
        if i[0]*i[1]<0:
            try:
                tmp = y2[abs(i[0]*i[1])]
                # print(i,'xcounted')
                ans+=tmp
            except:
                continue
    for i in y1:
        if i[0]*i[1]<0:
            try:
                tmp = x2[abs(i[0]*i[1])]
                # print(i,'ycounted')
                ans+=tmp
            except:
                continue
    try:
        tmp=y2[0]
        ans+=(m-1)*n
    except:
        try:
            tmp=x2[0]
            ans+=(n-1)*m
        except:
            pass
    print(ans)
