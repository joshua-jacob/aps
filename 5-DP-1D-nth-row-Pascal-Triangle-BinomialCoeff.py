"""
Binomial Coefficients nCk using DP.
DP - Pascal's Triangle
Using 1D Array for nth row of Pascal's traingle
"""

def combination_1D(n, k):
    C = [0]*(n)
    C[0] = 1
    print(0, C)
    for i in range(n):
        for j in range(min(i+1, k+1), -1, -1):
            C[j] += C[j-1]
        print(i+1, C)
    return C[k]

if __name__ == "__main__":
    n, k=map(int, input().split(' '))
    print(combination_1D(n, k))
