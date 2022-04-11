# https://www.codechef.com/JAN19B/problems/HP18/

#HP18
t = int(input())
while(t>0):
    n,a,b=map(int,input().split(' '))
    l = list(map(int,input().split(' ')))
    flag=False
    for i in range(n):
        if l[i]%a==0 or l[i]%b==0:
            flag=True
            break
    if flag is True:
        (acount,bcount)=(0,0)
        for i in range(n):
            if l[i]%a==0:
                acount+=1
            elif l[i]%b==0:
                bcount+=1
        if acount<=bcount:
            flag=False
        else:
            flag=True         
    if flag is True:
        print('BOB')
    else:
        print('ALICE')
    t-=1
