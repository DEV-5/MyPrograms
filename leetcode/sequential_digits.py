#!/usr/bin/python
"""
    Author: Vasudev.m
    Date: 19th Sept 2020
    Purpose: An integer has sequential digits if and only if each digit in the
    number is one more than the previous digit.Return a sorted list of all the
    integers in the range [low, high] inclusive that have sequential digits.
"""
import sys

def main():
    """
    This is the main function
    """
    print("The name of the Script is ", sys.argv[0])
    low = 1
    high = 12
    #lista = [high, low]
    obj = Solution()
    print(obj.sequentialdigits(low, high))

class Solution:
    """Doc string"""
    def __init__(self):# constructor
        print("Inside Constructor for Solution")
        self.count = 0

    def sequentialdigits(self, low: int, high: int) -> [int]:
        """ Function Annotations Are used"""
        alist = [low, 12, 23, 34, 45, high]
        print("none")
        self.count += 1
        return alist

    def printer(self):
        """ prints a proverb """
        print("Haste makes waste")
        self.count += 1

if __name__ == "__main__":
    main()
