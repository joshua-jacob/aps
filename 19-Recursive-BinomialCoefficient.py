"""
Calculates Binomial Coefficients nCk recursively
"""

def nCk_recursive(n, k):
    if k==0 or n==k:
        return 1
    else:
        return nCk_recursive(n-1,k)+nCk_recursive(n-1, k-1)

if __name__ == "__main__":
    n,k=map(int,input().split(' '))
    print(nCk_recursive(n,k))
