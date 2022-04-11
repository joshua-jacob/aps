"""
Program to perform BFS using adjacency list

Input format:
M N
V01 V02
V11 V12
 ...
VM1 VM2
"""
edges, vertices = map(int,input().split(' '))
adjacency_list = [[] for i in range(vertices)]

for i in range(edges):
	u,v = map(int,input().split(' '))
	adjacency_list[u-1].append(v)
	adjacency_list[v-1].append(u)

for i in range(vertices):
	print(adjacency_list[i])

queue = [1] #Starting node
traversal = [1] #Final traversal stored
visited = [False for i in range(vertices)]
visited[0] = True

while(queue):
	current_node = queue[-1]
	for i in adjacency_list[current_node-1]:
		if not visited[i-1]:
			visited[i-1] = True
			queue.insert(0,i)
			traversal.append(i)
	queue.pop()
	print(visited)

print('Final Traversal:',traversal)
