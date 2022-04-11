# https://www.codechef.com/NOV18B/problems/PRDRG

l=list(map(int,input().split(' ')))
t=l[0]
for i in range (1,t+1):
	n=l[i]
	x=1
	y=2**n
	if n>2 and n%2==0:
		for i in range(2,n,2):
			x+=(2**i)
	if n>2 and n%2==1:
		for i in range(1,n,2):
			x+=(2**i)
	print(x,y,end=' ')
