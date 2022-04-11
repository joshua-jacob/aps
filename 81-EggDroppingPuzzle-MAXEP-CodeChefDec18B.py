# https://www.codechef.com/DEC18B/problems/MAXEP

import math
coins=1000
N,c=map(int,input().split(' '))
if N>5:
	n=math.floor(math.log2(N))
	while(n*(n+1)//2 < N):
		n+=1
	(x,flag)=(0,0)
	while(x<N and n>0 and coins>0):
		x+=n
		print('1',min(x,N),flush=True)
		coins-=1
		flag=int(input())
		if flag==1:
			print('2',flush=True)
			coins-=c;
			break
		n-=1
	if flag==0:
		print('3',N,flush=True)
	else:
		flag=0
		for i in range(x-n+1,x):
			if coins>0:
				print('1',i,flush=True)
				coins-=1
				flag=int(input())
				if flag==1:
					print('2',flush=True)
					coins-=c
					break
		if flag==1:
			print('3',i,flush=True)
		else:
			print('3',x,flush=True)
else:
	flag=0
	i=1
	for i in range(1,N+1):
		print('1',i,flush=True)
		flag=int(input())
		coins-=1
		if flag==1:
			print('2',flush=True)
			coins-=c
			break
	print('3',i,flush=True)
