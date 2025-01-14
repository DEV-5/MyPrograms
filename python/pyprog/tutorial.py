#! /usr/bin/python
"""
Purpose: Generic Python code
Date: 18th Aug 2020
Author: Vasudev
"""
#import random
from random import randint as randi
import math
import sys
import os

#Data Types
A = 65
#A++  #Not allowed in python
print(A)
print("Data typeof A is ", type(A))
print("Data typeof A is ", type(float(A))) #Type casting
print("Data typeof A is ", type(chr(A))) #Type casting
print("Data typeof A is ", type(str(A))) #Type casting
print("Data typeof A is ", type(ord('a'))) #Type casting
#End of Data types

#print
print("No Newline.", end='')
print(15, 8, 1947, sep='/')
print("\n%04d %s %.2f %c" %(1, "Vdev", 3.147, 'A'))
#Endofprint
#Math
print((5+2), (5-2), (5*2), (5/2), (5**2), (5%2), (5//2), randi(1, 321)//3)
print("abs(-1)=%d exp(1)=%d" %(abs(-1), math.exp(2)))
print("max(12,13) = %d min(12,13) =%d log(e)=%d" %(max(12, 13), min(12, 13), math.log(math.exp(1))))
#math. floor ceil round sqrt sin cos tan asin acos atan sinh cosh tanh asinh
#acosh atanh hypot radians degrees
print("math.inf > 0 is ", math.inf > 0)
print("math.inf - math.inf = ", math.inf - math.inf)
#End of Math
#Conditional
#< > <= >= == !=
AGE = 90
if AGE > 24:
    print("You can drive a tractor trailer")
elif AGE >= 18:
    print("You can drive a car")
elif AGE >= 16:
    print("You can drive a automatic car")
else:
    print("You can't drive")
CANVOTE = True if AGE >= 18 else False
#End of Conditional
#String
STRI = "This is a string"
print(r"newline will be ignored \n")
print("hello"+"! "+"world")
print(STRI[0])  #First char of string
print(STRI[-1]) #last char os string
print(STRI[0:-1:2]) #print from 1st to last skipping every other var
STRI[2] = "r"
#End of String
#LISTs
g_list = ['tomatoes', 'oranges', 'carrots', 'cabbage']
h_list = ['score', 'dozen', 'killo']
glist_3 = [g_list, h_list]
g_list_2 = ["tomatoes", "oranges", "carrots", "cabbage"]+g_list
g_list.append("peas")
g_list.append("loop")
print("g_list_2: ", g_list_2)
print("glist_3", glist_3)
del g_list[5]
#print(g_list_2[2][0])
#print(glist_3[4][1][0])
del g_list
print("glist_3", glist_3)
#print(g_list)
#End of List
