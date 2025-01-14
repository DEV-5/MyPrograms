#!/usr/bin/python3
"""
    Author: Vasudev.m
    Date: 24th Sept 2020
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
    num = [3, 30, 34, 5, 9]
    obj = Solution()
    res = obj.largestnumber(num)
    print("\nThe Answer is ", res)

class Solution:
    """Doc string"""
    def __init__(self):# constructor
        print("Inside Constructor for Solution")
        self.count = 0

    def largestnumber(self, nums: [int]) -> str:
        """Doc strings"""
        res = ""
        nums.sort()
        for num in nums:
            print(num, " ", end='')
        self.count += 1
        return res

if __name__ == "__main__":
    main()
