#Date: 15-5-18 
import numpy
import sys 
print([sys.prefix, getattr(sys, "real_prefix", None)])
a = map(int, raw_input().split(" "))
print(a) 
b = numpy.array(a)
c=numpy.array_repr(b)
print(b)
print(c)    
exit(0)
