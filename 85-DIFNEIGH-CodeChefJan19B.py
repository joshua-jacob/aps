# https://www.codechef.com/JAN19B/problems/DIFNEIGH

t=int(input())
while(t>0):
    N,M=map(int,input().split(' '))
    n=min(N,M)
    m=max(N,M)
    matrix=[[0 for i in range(m)] for j in range(n)]
    k=0
    if n<=m:
        if n==1:
            if m<3:
                k=1
                for i in range(m):
                    matrix[0][i]=1
            else:
                k=2
                for i in range(m):
                    if i%4==0 or i%4==1:
                        matrix[0][i]=1
                    else:
                        matrix[0][i]=2
        elif n==2:
            if m==2:
                k=2
                matrix[0][0]=1
                matrix[0][1]=1
                matrix[1][0]=2
                matrix[1][1]=2
            else:
                k=3
                for i in range(0,m,6):
                    matrix[0][i]=1
                    matrix[1][i]=2
                    if i+1<m:
                        matrix[0][i+1]=1
                        matrix[1][i+1]=2
                    if i+2<m:
                        matrix[0][i+2]=3
                        matrix[1][i+2]=3
                    if i+3<m:
                        matrix[0][i+3]=2
                        matrix[1][i+3]=1
                    if i+4<m:
                        matrix[0][i+4]=2
                        matrix[1][i+4]=1
                    if i+5<m:
                        matrix[0][i+5]=3
                        matrix[1][i+5]=3
        elif n>2:
            k=4
            for i in range(n):
                for j in range(0,m,4):
                    if i%4==0 or i%4==1:
                        matrix[i][j]=1
                        if j+1<m:
                            matrix[i][j+1]=2
                        if j+2<m:
                            matrix[i][j+2]=3
                        if j+3<m:
                            matrix[i][j+3]=4
                    else:
                        matrix[i][j]=3
                        if j+1<m:
                            matrix[i][j+1]=4
                        if j+2<m:
                            matrix[i][j+2]=1
                        if j+3<m:
                            matrix[i][j+3]=2
    print(k)
    if N<=M:
        for i in range(N):
            print(' '.join(map(str,matrix[i])))
    else:
        rez = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
        for i in range(N):
            print(' '.join(map(str,rez[i])))
    t-=1
