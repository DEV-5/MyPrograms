#!/usr/bin/python2
import sys

def uncompress(buf):
    klist=[]
    fp2=open("data.txt",'r')
    slist=str(fp2.readlines())
    klist=slist.split()
    fp2.close()
    print(len(klist))
    print(klist)
    fp=open("dest.txt",'w')
    for w in buf.split():
            fp.write(klist[int(w)]+" ")

#MAIN CODE

fp=open("nfile.txt")
uncompress(fp.read())
print("\n\n\tDECOMPRESSION SUCCESSFUL: A NEW FILE HAS BEEN CREATED !")
