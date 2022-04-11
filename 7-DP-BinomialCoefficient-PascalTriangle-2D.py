"""
Binomial Coeffiecient nCk using DP.
DP - Pascals' Triangle
Using 2D Array to built up to n rows of the triangle
"""

def nCk(n, k):
    C=[[0]*(k+1) for i in range(n+1)]
    for i in range(n+1):
        for j in range(min(i+1,k+1)):
            if j == 0 or j == i:
                C[i][j]=1
            else:
                C[i][j]=C[i-1][j-1]+C[i-1][j]
    print("Pascal's Triangle")
    for i in C:
        print(i)
    return C[n][k]

if __name__ == "__main__":
    n,k=map(int,input().split(' '))
    print(nCk(n,k))
