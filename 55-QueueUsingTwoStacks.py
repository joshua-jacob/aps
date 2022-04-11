# Enter your code here. Read input from STDIN. Print output to STDOUT
t=int(input())
queue=[]
for q in range(t):
    s=input()
    if s[0]=='1':
        a,b=map(int,s.split(' '))
        queue.insert(0,b)
    elif s=='2':
        queue.pop()
    else:
        print(queue[-1])
