# https://www.codechef.com/FEB20B/problems/LONGCOOK/

linp = lambda a:list(map(int,input().split(' ')))
minp = lambda a:map(int,input().split(' '))
inp = lambda a:int(input())
MD = 1000000007
from math import ceil

lookUp = []
day=2
for i in range(1,401):
    lookUp.append(day)
    if ((i%400==0) or (i%4==0 and i%100!=0)):
        day-=1
    if day==0:
        day=7
    day-=1
    if day==0:
        day=7

# print(lookUp,len(lookUp),'lookUp')

prefixLookUp = []
for i in range(0,400):
    if (((i+1)%400==0) or ((i+1)%4==0 and (i+1)%100!=0)):
        if lookUp[i]==7:
            prefixLookUp.append(1)
        else:
            prefixLookUp.append(0)    
    elif lookUp[i]==6 or lookUp[i]==7:
        prefixLookUp.append(1)
    else:
        prefixLookUp.append(0)

# print(prefixLookUp,len(prefixLookUp),'PrefixlookUp')

for i in range(1,400):
    prefixLookUp[i]+=prefixLookUp[i-1]

# print(prefixLookUp,len(prefixLookUp),'PrefixlookUp')

t=inp(0)
for _ in range(t):
    m1,y1=minp(0)
    m2,y2=minp(0)
    # if y1%400==0 and y2%400==0:
    #     print(101*(y2-y1)//400)
    #     continue
    if m1>2:
        y1+=1
    if m2==1:
        y2-=1
    count=0
    lim1 = ceil(y1/400)*400
    lim2 = (y2//400)*400
    # print('lim1',lim1,'lim2',lim2)
    # print('y1',y1,'y2',y2)
    # for i in range(y1,lim1+1):
    #     #print('year',i)
    #     if ((i%400==0) or (i%4==0 and i%100!=0)):
    #     #    print('leap')
    #         if lookUp[(i-1)%400]==7:
    #             count+=1
    #     #        print('IntersectLeap')
    #     elif lookUp[(i-1)%400]==6 or lookUp[(i-1)%400]==7:
    #         count+=1
    #     #    print('intersect')
    # for i in range(lim2,y2+1):
    #     #print('year',i)
    #     if ((i%400==0) or (i%4==0 and i%100!=0)):
    #     #    print('leap')
    #         if lookUp[(i-1)%400]==7:
    #             count+=1
    #     #        print('IntersectLeap')
    #     elif lookUp[(i-1)%400]==6 or lookUp[(i-1)%400]==7:
    #         count+=1
    #     #    print('intersect')
    
    if lim1>lim2:
        print(prefixLookUp[max(0,(y2-lim2)%400-1)]-prefixLookUp[max(0,((y1-1)%400)-1)])
    else:
        count+=101*((lim2-lim1)//400)
        count+=101-prefixLookUp[max(0,((y1-1)%400)-1)]
        count+=prefixLookUp[max(0,(y2-lim2)%400-1)]
        print(count)
