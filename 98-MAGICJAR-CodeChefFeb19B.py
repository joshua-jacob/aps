# https://www.codechef.com/FEB19B/problems/MAGICJAR/

#MAGICJAR
t=int(input())
for testcase in range(t):
    n=int(input())
    a=list(map(int,input().split(' ')))
    print(sum(a)-n+1)
