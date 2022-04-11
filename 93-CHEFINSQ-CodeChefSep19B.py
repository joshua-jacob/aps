# https://www.codechef.com/SEPT19B/problems/CHEFINSQ/

from collections import Counter
from math import factorial
def comb(n,r):
	if n>r:
		return factorial(n)//(factorial(n-r)*factorial(r))
	else:
		return 1

t=int(input())
for _ in range(t):
	n,k=map(int,input().split(' '))
	l=list(map(int,input().split(' ')))
	l.sort()
	d = Counter(l)
	lst = list(d.items())
	ans=1
	for i in range(len(lst)):
#		print(k,lst[i])
		if k<lst[i][1]:
			ans=comb(lst[i][1],k)
			break
		else:
			k-=lst[i][1]
	print(ans)
