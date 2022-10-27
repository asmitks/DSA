# Shortest path in a multi-stage graph

def minJumps5(A,n):
	queue = [0]
	dist = [0] + [2147483647]*(n-1)
	visited = [1] + [0]*(n - 1)

	while(len(queue) != 0):
		#print(dist)
		x = queue.pop(0)
		for i in range(len(A[x])):
			if(visited[A[x][i]] == 0):
				visited[A[x][i]] = 1
				dist[A[x][i]] = dist[x] + 1
				queue.append(A[x][i])

	print(dist[n-1])


t = int(input())
for T in range(t):
	n = int(input())
	P = list(map(int,input().strip().split()))
	#print(minJumps2(P,n, 0,0))
	A = [[]*(n + 1) for i in range(n + 1)]

	for i in range(n):
		if(i + 1 <= n):
			A[i].append(1+i)
			# A[i][i+1] = 1
		if(i + P[i] <= n and i + P[i] >= 0 and P[i]!=1):
			#print(i, i + P[i])
			A[i].append(i + P[i])
			# A[i][i + P[i]] = 1
	n = n + 1
	#print(A)
	#A = list(set(A))

	print(A)
	minJumps5(A, n)
#print(minJumps(P,n,0, 0, -1))

#DP ● Optimal substructure ● Overlapping subproblems | Shortest path in a multi-stage graph
