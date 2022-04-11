"""
https://www.hackerrank.com/challenges/acm-icpc-team/problem

There are a number of people who will be attending ACM-ICPC World Finals. Each of them may be well versed in a number of topics. 
Given a list of topics known by each attendee, you must determine the maximum number of topics a 2-person team can know. 
Also find out how many ways a team can be formed to know that many topics.
"""

#!/bin/python3

import math
import os
import random
import re
import sys
from itertools import combinations
from collections import Counter

def countSetBits(n):
    count=0
    while(n):
        n&=n-1
        count+=1
    return count

# Complete the acmTeam function below.
def acmTeam(n,topic):
    l=list(combinations(range(n),2))
    arr=[]
    print('l',l)
    for i in l:
        arr.append(countSetBits(topic[i[0]]|topic[i[1]]))
    print('arr',arr)
    d=dict(Counter(arr))
    result = [max(d),d[max(d)]]
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    topic = []

    for _ in range(n):
        topic_item = int(input(),2)
        topic.append(topic_item)

    result = acmTeam(n,topic)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
