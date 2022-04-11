# https://www.codechef.com/NOV18B/problems/CHHAPPY

t=int(input())
while(t>0):
	n=int(input())
	flag=0
	a=list(map(int,input().split(' ')))
	ln=len(set(a))
	a.insert(0,0)
	A=[0]
	checkedA=[]
	checkeda=[]
	if ln>1 and ln<n:
		for i in range(1,n+1):
			A.append(a[a[i]])
		for i in range(1,n+1):
			(temp1,temp2)=(0,0)
			if a[i] in checkeda:
				temp1=1
			else:
				checkeda.append(a[i])
			if A[i] in checkedA:
				temp2=1
			else:
				checkedA.append(A[i])
			if temp2==1 and temp1==0:
				flag=1
				break
	if flag==0:
		print('Poor Chef')
	else:
		print('Truly Happy')
	t-=1
