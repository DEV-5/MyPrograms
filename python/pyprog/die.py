#!/sbin/usr/python3
import random


A = 0
B = []
ARR = range(10, 99)
#a=random.choice()
A = random.randint(1, 8)#generate a single psudo rand number
B = random.sample(ARR, 3)
#generate a random list of given size from a given list
C = random.uniform(12, 13) #'''generate a random real number
#in the range specified by the arguments'''
print(A)
print(B)
print(C)
this_prints(123)

"""
@input a
"""
def this_prints(a):
    print("This is an function and the value is %d\n", a)
