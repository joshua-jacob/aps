# https://www.codechef.com/APRIL20A/problems/STRNO/

linp = lambda a:list(map(int,input().split(' ')))
minp = lambda a:map(int,input().split(' '))
inp = lambda a:int(input())
import math

def primeFactors(n):
    count,lim=0,math.ceil(math.sqrt(n))
    while n%2==0:
        n//=2
        count+=1
    for i in range(3, lim, 2):
        while n%i==0:
            n//=i
            count+=1
    if n>2:
        count+=1
    return count

t=inp(0)
for _ in range(t):
    x,k=minp(0)
    val=primeFactors(x)
    if k<=val and x>=2**k:
        print(1)
    else:
        print(0)
