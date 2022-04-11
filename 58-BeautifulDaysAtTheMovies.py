"""
Given a range of numbered days, [i...j] and a number k, determine the number of days in the range that are beautiful. 
Beautiful numbers are defined as numbers where |i-reverse(i)| is evenly divisible by k. 
If a day's value is a beautiful number, it is a beautiful day. Print the number of beautiful days in the range.
"""

#!/bin/python3

import math
import os
import random
import re
import sys

def reverseIt(k):
    k=str(k)
    k="".join(reversed(k))
    return int(k)

# Complete the beautifulDays function below.
def beautifulDays(i, j, k):
    ans = 0
    for m in range(i, j+1):
        if(abs(m-reverseIt(m))%k==0):
            ans+=1
    return ans
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ijk = input().split()

    i = int(ijk[0])

    j = int(ijk[1])

    k = int(ijk[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
