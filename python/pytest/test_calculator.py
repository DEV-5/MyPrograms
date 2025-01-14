"""
Date: 27th Nov 2020
"""
import pytest
from calculator import Calculator, CalculatorError

def test_add():
    """
    there is no spoon
    """
    calculator = Calculator()
    result = calculator.add(2, 3)
    assert result == 5
    # Arrange
    # Act
    # Assert

def test_sub():
    """test case for substract fn"""
    calculator = Calculator()
    result = calculator.subtract(7, 2)
    assert result == 5

def test_mul():
    """test case for substract fn"""
    calculator = Calculator()
    result = calculator.multiply(80, 4)
    assert result == 320

def test_div():
    """test case for substract fn"""
    calculator = Calculator()
    result = calculator.divide(9, 3)
    assert result == 3

def test_weirdstuff():
    """test case for substract fn"""
    calculator = Calculator()
    with pytest.raises(CalculatorError):
        result = calculator.add("two", 3)

def test_weirderstuff():
    """test case for substract fn"""
    calculator = Calculator()
    with pytest.raises(CalculatorError):
        result = calculator.add("two", "three")
