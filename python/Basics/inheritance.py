#! /usr/bin/python3
"""
Author: V_DEV
DATE: 17th NOV 2020
Purpose: program on python inheritance
"""

class Employee:
    """"Generic Employee class which will be inherited by other classes"""
    def __init__(self, name = "bafoon", salary = 0, age = 22, role = "Default"):
        self.name        = name
        self.salary      = salary
        self.age         = age
        self.email       = name + "@email.com"
        self.role = role
    def employee_info(self):
        """Printing employee info"""
        print("Employee Name = ", self.name, " Email = ",self.email, " Salary = ",
                self.salary," Age = ", self.age," Designation =", self.role)
    def employee_clear(self):
        """Clearing Employee info"""
        self.name        = ""
        self.salary      = 0
        self.age         = 0
        self.email       = ""
        self.role        = ""

class Developer(Employee):
    """Developer class which is inherting Employee class"""
    role = "Software Developer"
    #def __init__(self, name, salary, age, role)
    #    super.__init__(name,salary,age,role)
    #    print("Role = ", role)

class Manager(Employee):
    """Manager class which is inherting Employee class"""
    role = "Project Manager"

class a:
    def cal(self,d,e):
        return d+e
class b(a):
    def cal(self,d,e):
        return d*e
class c(b):
    def cal(self,d,e):
        return d/e

if __name__ =="__main__":
    e1 = Developer()
    e1.employee_info()
    print(e1.role)
    e1.employee_clear()
    e1.employee_info()
    e2 = Manager()
    e2.employee_info()
    #print("Is e2 an instance Manager   :", isinstance(e2, Manager))
    #print("Is e2 an instance Employee  :", isinstance(e2, Employee))
    #print("Is e2 an instance Developer :", isinstance(e2, Developer))
    #print("Is Developer an subclass of Employee :", issubclass(Developer, Employee))
    #print("Is Manager an subclass of Employee :", issubclass(Manager, Employee))
    #print("Is Employee an subclass of Manager :", issubclass(Employee, Manager))
    ay = c()
    print(ay.cal(3,5))
