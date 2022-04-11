# https://www.codechef.com/MARCH19B/problems/JAIN/

#JAIN
from itertools import compress, product
def combinat(items):
    return ( set(compress(items,mask)) for mask in product(*[[0,1]]*len(items)) )
t=int(input())
while t>0:
    n=int(input())
    keys='aeiou'
    vowels=list(combinat(keys)) #returns power set of a,e,i,o,u
    vowels.pop(0) #removed empty set
    for i in range(31):
        vowels[i]=''.join(sorted(list(vowels[i]))) #sorted to maintain uniformity
    d={vow:0 for vow in vowels} #Dictionary with key as element of vowel power set and value as 0
    count=0
    arr=[]
    for i in range(n):
        tmp=input()
        arr.append(''.join(sorted(list(set(tmp)))))
    for i in range(n):
        d[arr[i]]+=1 #Count no of occurences in dictionary
    val = list(d.values()) #List of values
    key = list(d.keys()) #List of keys
    indkey=key.index('aeiou')
    val.pop(indkey)
    key.pop(indkey)
    for i in range(30):
        key[i]=set(key[i]) #Convert list to set for union operation
    for i in range(30): #Nested loop wokay because it is constant
        for j in range(30):
            if i!=j and len(key[i]|key[j])==5:
                count+=val[i]*val[j]
    count=count//2
    dval=d['aeiou']
    if dval!=0:
        if dval==1:
            count+=sum(val)
        else:
            count+=(dval-1)*dval//2
            for i in range(30):
                count+=val[i]*dval
    print(count)
    t-=1
