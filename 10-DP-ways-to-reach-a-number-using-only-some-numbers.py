"""
Coin Change Problem using DP
"""

def numberOfWays(n,num_array):
    arr = [0]*(n+1)
    arr[0]=1
    for num in num_array:
        for i in range(num,n+1):
            if arr[i-num]!=0:
                arr[i]+=arr[i-num]
    return arr

if __name__ == "__main__":
    n=int(input())
    num_array=list(map(int,input().split(' ')))
    # num_array=[3,5,10]
    print(numberOfWays(n,num_array))
