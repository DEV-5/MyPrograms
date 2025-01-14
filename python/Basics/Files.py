#Date:9-5-18
try:
    fp = open("thisisatextfile.txt",'r')
except Exception as E:
    print(E)
else:
    a=fp.readlines()
    b=fp.newlines()
    print(b) 
finally:
    print("closing file")
    fp.close()
    
#with

