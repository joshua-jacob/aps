# https://www.codechef.com/JAN19B/problems/MGAME

t=int(input())
while(t>0):
    n,p=map(int,input().split(' '))
    x=n//2 + 1
    if n==1 or n==2:
        print(p**3)
    else:
        print(x**2 + 3*(p-n)*(x+p-n))
    t-=1
