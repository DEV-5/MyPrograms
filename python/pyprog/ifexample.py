#!/bin/python

import math

if __name__ == '__main__':
    n = input("Enter a number between 1 to 100:")
    if n > 100 or n < 0: 
        print("you have entered an invalid number try again !")
        n= input("Enter a number between 1 to 100:")
    print("you have entered",n)
    if n%2 =
