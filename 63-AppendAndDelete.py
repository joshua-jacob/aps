"""
Given an integer, k, and two strings, s and t, determine whether or not you can convert s to t by performing exactly k 
of the above operations on s. If it's possible, print Yes. Otherwise, print No.
"""

#!/bin/python

import math
import os
import random
import re
import sys

# Complete the appendAndDelete function below.
def appendAndDelete(s, t, k):
    if s==t:
        return 'Yes'
    if k>=max(len(s),len(t)) and set(s)==set(t):
        return 'Yes'
    l=min(len(s),len(t))
    i=0
    while i<l and s[i]==t[i]:
        i+=1
    ans=max(0,len(s)-i)+max(0,len(t)-i)
    if ans<=k and (ans-k)%2==0:
        return 'Yes'
    else:
        return 'No'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = raw_input()

    t = raw_input()

    k = int(raw_input())

    result = appendAndDelete(s, t, k)

    fptr.write(result + '\n')

    fptr.close()
