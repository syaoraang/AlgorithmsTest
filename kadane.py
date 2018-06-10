arr = [1, 1, 1, 1, -4, 6, -2, 7, 1, -6, 5, 2, 1, -10, -10, 40]

start = 0 #Start index
end = 0 #end index
m = 0 #Local maximum
M = 0 #Global maximum

l = len(arr)

for i in range(l):
	m = m+arr[i]
	if(arr[i] >= m):
		m = arr[i]
		start = i
	if(m>M):
		M = m
		end = i
	pass

print "Start: " + str(start) + " end: " + str(end) + ", Total: " + str(M)