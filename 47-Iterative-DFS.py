class Graph: 
	def __init__(self,V): # Constructor 
		self.V = V	 # No. of vertices 
		self.adj = [[] for i in range(V)] # adjacency lists 

	def addEdge(self,v, w):	 # to add an edge to graph 
		self.adj[v].append(w) # Add w to v’s list. 

	def DFS(self,s):		 # prints all vertices in DFS manner from a given source. 
								# Initially mark all verices as not visited 
		visited = [False for i in range(self.V)] 

		stack = [] 
		stack.append(s) 
		while (len(stack)): 
			s = stack[-1] 
			stack.pop() 
			if (not visited[s]): 
				print(s,end=' ') 
				visited[s] = True
			for node in self.adj[s]: 
				if (not visited[node]): 
					stack.append(node) 


g = Graph(5); # Total 5 vertices in graph 
g.addEdge(1, 0); 
g.addEdge(0, 2); 
g.addEdge(2, 1); 
g.addEdge(0, 3); 
g.addEdge(1, 4); 

print("Iterative DFS...")
g.DFS(0) 
