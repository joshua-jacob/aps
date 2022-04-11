"""
A modified Kaprekar number is a positive whole number with a special property. 
If you square it, then split the number from the middle into two integers and sum those integers, you have the same value you started with.
"""

#!/bin/python3

import os
import random
import re
import sys
from math import ceil

def isKaprekar(n):
    sq = n*n
    s = str(sq)
    ln = len(s)
    d = ln//2
    if n==1 or n==9:
        return True
    if d>1:
        l, r = int(s[:d]), int(s[d:])
        if l+r == n:
            # print(l,r)
            return True
    return False

# Complete the kaprekarNumbers function below.
def kaprekarNumbers(p, q):
    ans = []
    for i in range(p, q+1):
        if isKaprekar(i):
            ans.append(i)
    if len(ans)==0:
        print('INVALID RANGE')
    else:
        print(*ans)

if __name__ == '__main__':
    p = int(input())

    q = int(input())

    kaprekarNumbers(p, q)
