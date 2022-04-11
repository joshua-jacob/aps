# https://www.codechef.com/DEC18B/problems/COMAS

t=int(input())
for testcases in range(t):
	n=int(input())
	old_list=[i for i in range(1,n+1)]
	new_list=old_list[:]
	while(len(new_list)>4):
		print('?',new_list[0],new_list[1],new_list[2],new_list[3],new_list[4],flush=True)
		x,y=map(int,input().split(' '))
		new_list.remove(x)
		new_list.remove(y)
	if len(new_list)==4:
		print('?',new_list[0],new_list[1],new_list[2],new_list[3],y,flush=True)
		x,y=map(int,input().split(' '))
		if x in new_list:
			new_list.remove(x)
		else:
			new_list.remove(y)
	(x,y,z)=(new_list[0],new_list[1],new_list[2])
	pset=set(new_list)
	qset=set(old_list)
	rdif=qset-pset
	setlist=list(rdif)
	(a,b,c)=(setlist[0],setlist[1],setlist[2])
	print('?',x,y,a,b,c,flush=True)
	t1,t2=map(int,input().split(' '))
	print('?',y,z,a,b,c,flush=True)
	t3,t4=map(int,input().split(' '))
	print('?',x,z,a,b,c,flush=True)
	t5,t6=map(int,input().split(' '))
	if t1==t3 and t2==t4:
		print('!',y,flush=True)
	elif t1==t5 and t2==t6:
		print('!',x,flush=True)
	elif t3==t5 and t4==t6:
		print('!',z,flush=True)
