W=5
weights=[1,3,4,5]
val=[1,2,3,4]
n=len(weights)
knapsack=[[0]*(W+1) for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,W+1):
        if weights[i-1]<=j:
            knapsack[i][j]=max(knapsack[i-1][j],val[i-1]+knapsack[i-1][j-weights[i-1]])
        else:
            knapsack[i][j]=knapsack[i-1][j]

for i in knapsack:
    print(i)
