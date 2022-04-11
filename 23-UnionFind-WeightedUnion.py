"""
Union Find/Disjoing Set Union
Root method with Weighted Union
"""

def root(ar, i):
    while( i!=ar[i]):
        i=ar[i]
    return i

def find(ar, u, v):
    if root(ar,u)==root(ar,v):
        return True
    else:
        return False

def weightedUnion(ar, size, u, v):
    rootu, rootv = root(ar, u), root(ar, v)
    if size[rootu]<size[rootv]:
        ar[rootu] = ar[rootv]
        size[rootv] += size[rootu]
    else:
        ar[rootv] = ar[rootu]
        size[rootu] += size[rootv]

if __name__ == "__main__":
    arr = [i for i in range(5+1)]
    size = [1 for i in range(5+1)]
    weightedUnion(arr,size,0,1)
    print(arr,size)
    weightedUnion(arr,size,1,2)
    print(arr,size)
    weightedUnion(arr,size,3,2)
    print(arr,size)
