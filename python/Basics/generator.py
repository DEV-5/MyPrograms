"""
Date : 27th Nov 2020
Author : Vasudev M
"""

def square_generator(nums):
    """example for genrator function"""
    for num in nums:
        yield num*num #Generates output on the go

def square_normal(nums):
    """example for normal squaring function"""
    lista = []
    for num in nums:
        lista.append(num*num)
    return lista

if __name__ == "__main__":
    list1 = [1,2,3,4,5]
    my_square = square_generator(list1)
    for num in my_square:
        print(num)
    try:
        print(next(my_square))
    except StopIteration as error:
        print("an error occured",error.value)
    #listcomprehention
    my_nums = [x*x for x in [1,2,3,4,5]]
    #listcomprehention with generator
    my_nums = (x*x for x in [1,2,3,4,5])
    print(next(my_nums))
    print(next(my_nums))
