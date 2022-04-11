"""
Dynamic Programming
Rod Cutting Problem for maximum product
"""

def calc_max(n,result):
    for i in range(2,n+1):
        for j in range(1,i//2+1):
            # print(i,j,result[i],j*(i-j),j*result[i-j])
            result[i]=max(result[i],j*(i-j),j*result[i-j])
    return result

if __name__=='__main__':
    n=int(input())
    result=[0]*(n+1)
    result=calc_max(n,result)
    print(result)
