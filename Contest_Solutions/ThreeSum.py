# Python3 program to find a triplet
# that sum to a given value

# returns true if there is triplet with
# sum equal to 'sum' present in A[].
# Also, prints the triplet
def find3Numbers(A, summ):

	# Fix the first element as A[i]
	for i in range( 0, len(A)-2):

		for j in range(i + 1, len(A)-1):
			
			# Now look for the third number
			for k in range(j + 1, len(A)):
				if A[i] + A[j] + A[k] == summ:
					print("Triplet is", A[i], ",", A[j], ",", A[k])
					return True
	
	# If we reach here, then no
	# triplet was found
	return False

# Driver program to test above function
A = [1, 4, 45, 6, 10, 8]
summ = 22
find3Numbers(A, summ)

# This code is contributed by Smitha Dinesh Semwal
