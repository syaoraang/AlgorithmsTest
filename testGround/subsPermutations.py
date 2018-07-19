s = "abbc"
b = "cbabadcbbabbcdabaabccbabc"

dic = {}
indexes = []

for i in s:
	if not (i in dic):
		dic[i] = 1
	else:
		dic[i] = dic[i]+1

window = len(s)
for j in range(0, len(b)-3):
	i = b[j]
	tmp = {}
	for k in dic.keys():
		tmp[k] = dic[k]
	c = 0
	keep = True
	while keep and c<window:
		i = b[j+c]
		if i in tmp and tmp[i]>0:
			tmp[i] = tmp[i] - 1
			keep = True
			c = c + 1
			pass
		else:
			keep = False
	if c == window:
		indexes.append(j)

print indexes
