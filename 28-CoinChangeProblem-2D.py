N=int(input())
A=list(map(int,input().split()))
A.insert(0,0)
M=[]
for i in range(0,len(A)):
	l=[]
	for j in range(0,N+1):
		if j==0:
			l.append(1)
		else:
			l.append(0)
	M.append(l)
A.sort()
for i in range(1,len(A)):
	for j in range(0,N+1):
		if A[i]>j:
			M[i][j]=M[i-1][j]
		else:
			M[i][j]=M[i-1][j]+M[i][j-A[i]]
print(M[i][j])
for i in M:
	print(i)
