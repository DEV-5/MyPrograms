#! /usr/bin/python3
"""
Author: Vasudev
Date: 17th Nov 2020
Purpose: The provided code stub will read in a dictionary containing key/value
         pairs of name:[marks] for a list of students. Print the average of the
         marks array for the student name provided, showing 2 places after the
         decimal.
Link: https://www.hackerrank.com/challenges/finding-the-percentage/problem
"""
import math 

if __name__ == "__main__":
    Testinput = True
    if Testinput :
        n = 9
        names = ["Krishna", "Arjun", "Malika"]
        marks= [[67,68,69], [70, 98, 63], [52, 56, 60]]
        student_marks = dict(zip(names,marks))
        print(student_marks)
        #student_marks = {"Krishna":[67,68,69], "Arjun":[70 98 63], "Malika":[52 56 60]}
        pick = "Malika"
        Average = sum(student_marks[pick])/float(len(student_marks[pick]))
        print("AVERAGE %.2f "%(Average))
