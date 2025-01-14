
#!/bin/python

import math
import os
import random
import re
import sys

# Complete the circularArrayRotation function below.
def circularArrayRotation(a, m,n,k):
    if n ==1:
        return n
    result =[]
    k = k % n
    b =[]
    #print(a[m])
    for e in xrange(k):
        b.append(a[n-k+e])
    for j in xrange(0,n-k):#shifting the array by one index
        b.append(a[j])
    a = b

    #print(a)
    for i in xrange(len(m)):
        result.append(a[m[i]])
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nkq = raw_input().split()

    n = int(nkq[0])

    k = int(nkq[1])

    q = int(nkq[2])

    a = map(int, raw_input().rstrip().split())

    m = []

    for _ in xrange(q):
        m_item = int(raw_input())
        m.append(m_item)

    result = circularArrayRotation(a, m,n,k)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
