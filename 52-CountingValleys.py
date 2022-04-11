"""
Given Gary's sequence of up ('U') and down ('D') steps during his last hike, find and print the number of valleys he walked through.

A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.

A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
"""

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    count,valley=0,0
    for i in s:
        if i=='D':
            count+=1
        if i=='U':
            count-=1
        if count==0 and i=='U':
            valley+=1
    return valley

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
