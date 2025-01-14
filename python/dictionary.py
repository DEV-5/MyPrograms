
import sys

mydict={"True":1,"False":0}
#print mydict.keys()
print mydict.get('True')
print mydict.items()
for(key, value) in mydict.iteritems():
    print key,value
