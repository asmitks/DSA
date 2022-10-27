from collections import defaultdict
from collections import deque

class Graph:

	# Constructor
	def __init__(self):

		# default dictionary to store graph
		self.graph = defaultdict(list)

	# function to add an edge to graph
	def addEdge(self,u,v):
		self.graph[u].append(v)

	# Function to print a DFS of graph
	def DFS(self, s):

		# Mark all the vertices as not visited
		visited = [False] * (max(self.graph) + 1)

		# Create a queue for BFS
		stack = deque()

		stack.append(s)
		visited[s] = True

		while len(stack) > 0:

			s = stack.pop()
			print (s, end = " ")

			for i in self.graph[s]:
				if visited[i] == False:
					stack.append(i)
					visited[i] = True
		print("")

# Driver code

# Create a graph given in
# the above diagram
g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print("Following is Depth First Traversal (starting from vertex 0)")
g.DFS(0)

# This code is contributed by Neelam Yadav
