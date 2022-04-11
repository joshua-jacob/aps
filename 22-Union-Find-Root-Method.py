"""
Union Find/Disjoint Set Union
Root Method
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

def union(ar, n, u, v):
    rootu, rootv = root(ar,u), root(ar,v)
    ar[rootu]=rootv

