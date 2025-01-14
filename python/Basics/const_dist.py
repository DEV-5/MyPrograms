#!/usr/bin/python3
"""
Name: vasudev
Date: 11th Nov 2020
"""
class Base1:
    """
    base class with constructor and distructor
    """
    def __init__(self):
        print("Base1: hello i am in a constructor")

    def __del__(self):
        print("Base1: hello i am in a destructor")
    def square(self,a):
        """method to Square a number"""
        return a*a
    def cube(self,b):
        """method to Cube a number"""
        return b*b*b

class Base2:
    """
    base class with constructor and distructor
    """
    def __init__(self):
        print("Base2: hello i am in a constructor")

    def __del__(self):
        print("Base2: hello i am in a destructor")
    def square(self,a):
        """method to Square a number"""
        return a*a
    def cube(self,b):
        """method to Cube a number"""
        return b*b*b

class Child(Base1,Base2):
    """
    Child class inheriting base class
    """
    #def __init__(self):
    #   print("Child: inside constructor")
    def __init__(self,var):
        print("Child: inside constructor 2")
        super().__init__()
        super().__del__()
        super(Child, self).__init__() #python 2 style call
    def __del__(self):
        print("Child: inside destructor ")
    #def __init__(self, *args, **kwargs):

#run this code only if this is run as main file
if __name__ == '__main__':
    print("hello")
    print("hi")
    #a = Base()
    a = Child(10)
    print("4*4 = ",a.square(4),"20*20*20 = ",a.cube(20))
