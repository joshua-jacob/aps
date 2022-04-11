"""
Python program to generate first n triangular numbers
"""
n=int(input())
tri=[]
for i in range(1,n):
    tri.append(i*(i+1)//2)
print(tri)
