"""
    Date 30th Nov 2020
    author: Vasudev m
    sub: Oop concepts in python
"""

class Employee:
    """
    a dummy class for illustration
    """
    raise_amount = 1.04
    employee_count = 0
    def __init__(self, first='/0', last='/0', pay=0):
        """
        NOTE: if default values are not provided an non argument object
        declaration call will cause an error.
        """
        self.first  = first
        self.last   = last
        self.pay    = pay
        self.email = first + '.' + last +'@company.com'
        Employee.employee_count += 1
    def fullname(self):
        """print the full name iof employee"""
        print("{}.{}".format(self.first, self.last),end='')
    def employee_info(self):
        """Print fullname, emailid and pay of the employee"""
        self.fullname()
        print("  {} {} ".format(self.email, self.pay))
    def apply_raise(self):
        """apply """
        self.pay = int(self.pay * self.raise_amount)
    @classmethod
    def set_raise_amt(cls, amount):
        """Example of a class method where don't need to pass the object"""
        cls.raise_amount = amount
    @classmethod
    def from_string(cls, emp_str):
        """method to initialize Employee object from string"""
        first, last, pay = emp_str.split('-')
        return cls(first, last, pay)
    @staticmethod
    def is_workday(day):
        """"Return True if weekday else false"""
        if day.weekday() == 5 or day.weekday() == 6:
            return False
        return True
    def __repr__(self):
        """useful for debugging call this fn if print(object) is called"""
        return "Employee('{}','{}' ,'{}')".format(self.first, self.last, self.pay)
    def __str__(self):
        """print object in user understandable format call this fn if
        print(object) is called"""
        return '{} - {}'.format(self.fullname(), self.email)
    def __len__(self):
        return len(self.first)+len(self.first)

class Developer(Employee):
    """create a derived class"""
    raise_amount = 1.10
    def __init__(self, first, last, pay, prog_lang):
        super().__init__(first, last, pay)
        self.prog_lang = prog_lang

class Manager(Employee):
    """create a derived class"""
    def __init__(self, first, last, pay, employees=None):
        super().__init__(first, last, pay)
        if employees is None:
            self.employees = []
        else:
            self.employees = employees
    def add_emp(self,emp):
        """Add an employee to the manager"""
        if emp not in self.employees:
            self.employees.append(emp)
    def remove_emp(self,emp):
        """Remove an employee from manager"""
        if emp in self.employees:
            self.employees.remove(emp)
    def print_emp(self):
        """print employees under manager"""
        for emp in self.employees:
            print("-->", emp.fullname())

class Student:
    """ student class defintion"""
    def __init__(self, first, last):
        self.first = first
        self.last = last
        #if last or first name is update this wont update
        #self.email = first + '.' + last + '@email.com'
    """@property allows calling email like variable preventing
    existing code using email from breaking"""
    @property
    def email(self):
        return '{}.{}@email.com'.format(self.first, self.last)
    @property
    def fullname(self):
        """return fullname of Student object"""
        return'{} {}'.format(self.first, self.last)
    @fullname.setter
    def fullname(self, name):
        first, last = name.split(' ')
        self.first = first
        self.last  = last
    @fullname.deleter
    def fullname(self):
        print("Deleting Name")
        self.first = None
        self.last  = None
    def __repr__(self):
        """useful for debugging call this fn if print(object) is called"""
        return "Student('{}','{}')".format(self.fullname, self.email)

if __name__ == '__main__':
    #Vid 1 https://youtu.be/ZDa-Z5JzLYM
    print(Employee.employee_count)
    emp_1 = Employee() # not passing any arguments to intializer
    emp_2 = Employee('M','Ravi',90000)
    print(Employee.employee_count)
    #initializing emp_1 object
    emp_1.first = "M"
    emp_1.last = "VDEV"
    emp_1.email = "vdev@devmail.com"
    emp_1.pay = "600000"
    print(emp_1.email)
    print(emp_2.email)
    #Vid 2 https://youtu.be/BJ-VvGyQxho
    print("------------------------------------------------------------------")
    print(Employee.__dict__)
    print(emp_1.__dict__)
    print("------------------------------------------------------------------")
    emp_1.employee_info() #below call is the actual reperesentation of this call
    Employee.employee_info(emp_2)
    Employee.raise_amount = 1.05
    print(emp_1.raise_amount)
    print(emp_2.raise_amount)
    print("------------------------------------------------------------------")
    emp_1.raise_amount = 1.06
    print(emp_1.raise_amount)
    print(emp_2.raise_amount)
    print("------------------------------------------------------------------")
    #Vid 3 https://youtu.be/rq8cL2XMM5M
    emp_3 = Employee('M','Ravi',90000)
    Employee.set_raise_amt(1.5)
    print(emp_2.raise_amount)
    print(emp_3.raise_amount)
    Employee.employee_info(emp_2)
    emp_str_4 = "Test-employee-50000"
    emp_4 = Employee.from_string(emp_str_4)
    emp_4.employee_info()
    import datetime
    my_date = datetime.date(2020,11,30)
    print(Employee.is_workday(my_date))
    print("------------------------------------------------------------------")
    #Vid 4 https://youtu.be/RSl87lqOXDE

    dev_1 = Developer('corey','schafer', 90000, 'c')
    dev_2 = Developer('Test','Employee', 50000, 'python')
    #print(help(Developer)) #To know mro and inherited methods & variables
    dev_1.employee_info()
    print(dev_1.pay)
    dev_1.apply_raise()
    print(dev_1.pay)

    mrg1 = Manager('sue', 'smith', 95000, [dev_1])
    mrg1.employee_info()
    mrg1.print_emp()
    mrg1.add_emp(dev_2)
    mrg1.print_emp()

    print("Is e2 an instance Employee  :", isinstance(dev_1, Employee))
    print("Is e2 an instance Developer :", isinstance(dev_1, Developer))
    print("Is Developer an subclass of Employee :", issubclass(Developer, Employee))
    print("Is Manager an subclass of Employee :", issubclass(Manager, Employee))
    print("Is Employee an subclass of Manager :", issubclass(Employee, Manager))
    print("------------------------------------------------------------------")
    print(mrg1)

    print("------------------------------------------------------------------")
    #Vid 6 https://youtu.be/jCzT9XFZ5bw
    stu_1 = Student('Harry', 'potter')
    print(stu_1)
    stu_1.fullname = 'john wick'
    print(stu_1.fullname," - ",stu_1.email)
    del stu_1.fullname
    print(stu_1)
