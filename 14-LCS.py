"""
DP - Longest Common Subsequence
Works for both String and Integer input
Also returns the indices which map to the LCS.
"""

def getLCSval(a,b,LCS):
    val=[]
    n1,n2=len(LCS),len(LCS[0])
    i,j=n1-1,n2-1
    while i>0 and j>0:
        if a[i-1]==b[j-1]:
            val.insert(0,a[i-1])
            i-=1
            j-=1
        elif LCS[i-1][j]>LCS[i][j-1]:
            i-=1
        else:
            j-=1
    return val

def LongestCommonSubsequence(a, b):
    n1,n2=len(a),len(b)
    LCS = [[0]*(n2+1) for i in range(n1+1)]
    for i in range(n1+1):
        for j in range(n2+1):
            if a[i-1]==b[j-1]:
                LCS[i][j]=LCS[i-1][j-1]+1
            else:
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1])
    val=getLCSval(a,b,LCS)
    return LCS,val

if __name__ == "__main__":
    # For String input:
    # s1=input()
    # s2=input()

    # For integer input:
    s1 = list(map(int,input().split(' ')))
    s2 = list(map(int,input().split(' ')))
    LCS,val=LongestCommonSubsequence(s1,s2)
    for i in LCS:
        print(i)
    print('Value of LCS =',val)
