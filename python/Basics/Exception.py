
#Date:8-5-18

try:
    val = raw_input("please enter the no people in the room:")
    print("Each person will get %d$"%(6000/int(val)))

except  ArithmeticError as E:
    print("An Arithmetic error has occured: {0}".format(E))
except Exception  as E2:
    print(E2)

finally:#will be executed wether an Exception has occured or not
    print("inside Finally......")
