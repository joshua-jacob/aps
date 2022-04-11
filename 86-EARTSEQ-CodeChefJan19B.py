#EARTSEQ
t=int(input())
MAX = 611960
prime = [True for i in range(MAX + 1)] 
arr = []
def SieveOfEratosthenes(): 
    prime[1] = False
    for p in range(2, MAX + 1): 
        if (prime[p] == True):
            arr.append(p)
            i = p * 2
            while(i <= MAX): 
                prime[i] = False
                i = i + p 
SieveOfEratosthenes()
while(t>0):
    n=int(input())
    if n==3:
        print(6,10,15)
    else:
        final=[6]
        j=0
        for j in range(3,n//2+2):
            if j%2 == 0:
                final.extend((arr[j]*2,arr[j]*3))
            else:
                final.extend((arr[j]*3,arr[j]*2))
        final.pop()
        if n%2==0:
            final.extend((arr[j]*5,10))
        else:
            final.extend((arr[j]*5,arr[j+1]*5,2*arr[j+1]))
        print(' '.join(map(str,final)))
    t-=1
