"""
Union Find/Disjoing Set Union
Brute Force
"""

def find(ar, u, v):
    if ar[u]==ar[v]:
        return True
    else:
        return False

def union(ar, n, u, v):
    temp = ar[u]
    for i in range(n):
        if ar[i]==temp:
            ar[i] = ar[v]

if __name__ == "__main__":
    ar = [0,1,2,3,4,5,6,7,8,9]
    n=len(ar)
    print(ar)
    union(ar,n,2,1)
    print(ar)
    union(ar,n,4,3)
    print(ar)
    union(ar,n,8,4)
    print(ar)
    union(ar,n,9,3)
    print('final',ar)
    print(find(ar,0,7))
    print(find(ar,8,9))
