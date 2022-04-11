# https://www.codechef.com/DEC19B/problems/SUBSPLAY

from collections import defaultdict
linp = lambda a:list(map(int,input().split(' ')))
minp = lambda a:map(int,input().split(' '))
inp = lambda a:int(input())
MD=1000000007

t=inp(0)
for _ in range(t):
	n=inp(0)
	s=input()
	k,temp,flag=0,0,0
	d=defaultdict(list)
	for i in range(n):
		d[s[i]].append(i)
#	print(d)
	for i in d.values():
		i1,dif=-1,MD
#		print(i)
		l=len(i)
		if l==1:
			continue
		#i.sort()
		dlst=[i[j+1]-i[j] for j in range(l-1)]
#		for j in range(l-1):
#			temp=i[j+1]-i[j]
#			print('entered',temp)
#			if (i[j+1]-i[j])<dif:
#				i1=j
#				dif=i[j+1]-i[j]
		k=max(k,n-min(dlst))
#		print('new k',k)
	print(k)
