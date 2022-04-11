"""
Set ith bit of a number
"""

def set_ith_bit(n, i):
    n = n | (1<<i)
    return n

if __name__ == "__main__":
    print(set_ith_bit(5,1))
    print(set_ith_bit(6,0))
    print(set_ith_bit(14,3))
