# https://www.codechef.com/MARCH19B/problems/CHDIGER/

t=int(input())
for _ in range(t):
    n,d=map(int,input().split(' '))
    dig = [int(x) for x in str(n)]
    digits=len(dig)
    for k in range(10):
        m=min(dig)
        while dig[0]!=m:
            dig.pop(0)
        count=0
        rem=len(dig)
        for i in range(rem-1):
            i-=count
            if dig[i]>dig[(i+1)] or dig[i]>d:
                dig.pop(i)
                count+=1
        if dig[-1]>d:
            dig.pop()
        while(len(dig)!=digits):
            dig.append(d)
    final=[str(x) for x in dig]
    result=''.join(final)
    print(result)
