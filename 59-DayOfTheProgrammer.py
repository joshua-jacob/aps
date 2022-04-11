"""
Given a year, y, find the date of the 256th day of that year according to the official Russian calendar during that year. 
Then print it in the format dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy is y.

From 1700 to 1917, Russia's official calendar was the Julian calendar; since 1919 they used the Gregorian calendar system. 
The transition from the Julian to Gregorian calendar system occurred in 1918, when the next day after January 31st was February 14th. 
This means that in 1918, February 14th was the 32nd day of the year in Russia.
"""

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def dayOfProgrammer(year):
    if year>1918:
        if year%4==0 and year%100!=0:
            return '12.09.'+str(year)
        elif year%400==0:
            return '12.09.'+str(year)
        else:
            return '13.09.'+str(year)
    elif year<1918:
        if year%4==0:
            return '12.09.'+str(year)
        else:
            return '13.09.'+str(year)
    else:
        return '26.09.'+str(year)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()
