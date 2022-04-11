#!/bin/python3

import math
import os
import random
"""
Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
"""

import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    d={}
    for i in ar:
        try:
            d[i]+=1
        except:
            d[i]=1
    count=0
    for i in d.values():
        count+=i//2
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
