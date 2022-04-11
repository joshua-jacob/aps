# https://www.codechef.com/MARCH20B/problems/ADASHOP2

t=int(input())
moves = [(2,2),(1,3),(3,1),(2,2),(3,3),(1,5),(5,1),(3,3),(4,4),(1,7),(7,1),(4,4),(5,5),(2,8),(8,2),(5,5),(6,6),(4,8),(8,4),(6,6),(7,7),(6,8),(8,6),(7,7),(8,8)]
for _ in range(t):
    r0,c0=map(int,input().split(' '))
    if r0==1 and c0==1:
        print(25)
        for i in moves:
            print(i[0],i[1]) 
    elif r0==c0:
        print(26)
        print(1,1)
        for i in moves:
            print(i[0],i[1]) 
    else:
        print(27)
        mean = (r0+c0)//2
        print(mean,mean)
        print(1,1)
        for i in moves:
            print(i[0],i[1]) 
