# https://www.codechef.com/FEB20B/problems/THEATRE/

linp = lambda a:list(map(int,input().split(' ')))
minp = lambda a:map(int,input().split(' '))
inp = lambda a:int(input())
MD = 1000000007
from itertools import permutations

t=inp(0)
profitlist=[]
for _ in range(t):
    n=inp(0)
    freq=[[0]*4 for i in range(4)]
    for i in range(n):
        l=input().split(' ')
        l[1]=int(l[1])
        if l[0]=='A':
            freq[0][l[1]//3%4]+=1
        if l[0]=='B':
            freq[1][l[1]//3%4]+=1
        if l[0]=='C':
            freq[2][l[1]//3%4]+=1
        if l[0]=='D':
            freq[3][l[1]//3%4]+=1
    #for i in freq:
    #    print(i)
    l=list(permutations([0,1,2,3]))
    maxprofit=-9999999999
    for i in l:
        tmp=[freq[j][i[j]] for j in range(4)]
        tmp.sort(reverse=True)
        profit,ticket=0,100
        for j in tmp:
            if j==0:
                profit-=100
            else:
                profit+=j*ticket
                ticket-=25
        #print(i,tmp,profit)
        maxprofit=max(maxprofit,profit)
    profitlist.append(maxprofit)
    print(maxprofit)
print(sum(profitlist))
