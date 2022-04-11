# https://www.codechef.com/APRIL19B/problems/STRCH/

t=int(input())
for _ in range(t):
    n=int(input())
    l=input().split(' ')
    (s,x)=(l[0],l[1])
    count=0
    for i in range(n):
        if s[i]==x:
            count+=n-i
            continue
        for j in range(i+1,n):
            if s[j]==x:
                count+=n-j
                break
    print(count)
