T=int(input())
for i in range(T):
	N=int(input())
	A=list(map(int,input().split()))
	origavg=sum(A)/N
	flag=0

	for x in range(N):
		if (origavg*N-A[x])/(N-1)==origavg:
			print(x+1)
			flag=1
			break
	if(flag==0):
		print("Impossible")
