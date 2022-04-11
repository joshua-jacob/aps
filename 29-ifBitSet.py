"""
Checks if ith bit is set in a number
"""

def ifBitSet(n, i):
    if n & (1<<i) == 0:
        return False
    else:
        return True

if __name__ == "__main__":
    print(ifBitSet(5,0))
    print(ifBitSet(5,1))
    print(ifBitSet(5,2))
