"""
Prints first n catalan numbers
"""

n=int(input())
catalan=[1]
for i in range(1,n):
    catalan.append(catalan[-1]*(4*i+2)//(i+2))
print(catalan)
