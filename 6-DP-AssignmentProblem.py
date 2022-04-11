"""
Assignment Problem using Bitwise DP
"""

def countSetBits(n):
    count = 0
    while n > 0:
        n = n & (n-1)
        count+=1
    return count

def isBitSet(n, i):
    if n & (1 << i) == 0:
        return False
    else:
        return True

def set_ith_bit(n, i):
    n = n | (1 << i)
    return n

def AssignmentDP(n, cost):
    dp = [float('inf')]*(2**n)
    dp[0] = 0
    for mask in range(2**n):
        x = countSetBits(mask)
        for j in range(n):
            if not isBitSet(mask, j):
                temp = set_ith_bit(mask, j)
                dp[temp] = min(dp[temp], dp[mask] + cost[x][j])
    return dp

if __name__ == "__main__":
    n = int(input())
    cost = []
    for i in range(n):
        cost.append(list(map(int, input().split(' '))))
    print('Optimal Cost:', AssignmentDP(n,cost))
