def reverse(s, i=0):
	n = len(s)
	if i == n//2:
		return
	s[i], s[n-i-1] = s[n-i-1], s[i]
	reverse(s, i+1)
	
string = input()
s = list(string)
reverse(s)
print(''.join(s))
