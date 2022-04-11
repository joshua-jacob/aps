"""
Given a time in - hour AM/PM format (hh:mm:ssAM/PM), convert it to military (24-hour) time (hh:mm:ss).
"""


#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    hr = s[-2:]
    if hr=='AM':
        ans = int(s[:2])
        if ans==12:
            return "00"+s[2:len(s)-2]
        return s[:len(s)-2]
    else:
        ans=int(s[:2])
        if ans!=12:
            ans+=12
        ans = str(ans) + s[2:len(s)-2]
        #print(ans)
        return ans

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
