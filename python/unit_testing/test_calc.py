"""
Name: Vasudev M
Date: 3rd Dec 2020
purpose: To test
"""
import unittest
import calc

class TestCalc(unittest.TestCase):
    """Test class to validate test function in calc module"""
    def test_add(self):
        """ test cases to validate input"""
        self.assertEqual(calc.add(10,5), 15)
        self.assertEqual(calc.add(1,-1), 0)
        self.assertEqual(calc.add(-2,-5), -7)
        self.assertEqual(calc.add(-2.2,-5),-7.2)

    def test_substract(self):
        """ test cases to validate input"""
        self.assertEqual(calc.subtract(10,5), 5)
        self.assertEqual(calc.subtract(-1,1), -2)
        self.assertEqual(calc.subtract(-1,-1), 0)
        self.assertEqual(calc.subtract(-1.7,-1), -0.7)

    def test_multiply(self):
        """ test cases to validate input"""
        self.assertEqual(calc.multiply(10,5), 50)
        self.assertEqual(calc.multiply(1,-1), -1)
        self.assertEqual(calc.multiply(-1,-1), 1)
        self.assertEqual(calc.multiply(7,-1.5), -10.5)

    def test_divide(self):
        """ test cases to validate input"""
        self.assertEqual(calc.divide(10,5), 2)
        self.assertEqual(calc.divide(1,-1), -1)
        self.assertEqual(calc.divide(-1,-1), 1)
        self.assertEqual(calc.divide(5,-2), -2.5)
        self.assertRaises(ValueError, calc.divide, 10, 0)
        #using context manager while rasing exceptions
        with self.assertRaises(ValueError):
            calc.divide(13,0)
