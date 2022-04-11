MAX = 611960 #First 50k primes
prime = [True for i in range(MAX + 1)] 
arr = []
def SieveOfEratosthenes(): 
    #prime[0] = False
    prime[1] = False
    for p in range(2, MAX + 1): 
        if (prime[p] == True): 
            i = p * 2
            while(i <= MAX): 
                prime[i] = False
                i = i + p 
    for p in range(2,MAX+1):
        if prime[p]:
            arr.append(p)
if __name__=='__main__':
    SieveOfEratosthenes()
    n=int(input())
    for i in range(n):
        print(i,prime[i])
    print(arr[:10])
    
