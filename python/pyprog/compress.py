#!/usr/bin/python2
nlist=[]
import sys
def compress(buf):
    words={}
    global nlist 
    buff=""
    fp=open("nfile.txt",'w')
    for word in buf.split(""):
        if words.has_key(word):
            words[word]+=1
        else:
            words[word]=1
            
    nlist=list(words.keys())
   #print words.items()
    print (nlist)
    for w in buf.split():
        i=0
        while(w!=nlist[i]):
            i=i+1
        fp.write(str(i)+" ")#type casting i to a string
    return fp.tell()
#end of compress

def uncompress(buf):
    print(nlist)
    fp=open("uncomp.txt",'w')
    for w in buf.split():
            fp.write(nlist[int(w)])

#MAIN CODE
if(len(sys.argv)!=2):
    print("incorrect no of arguments")
    exit()

fp=open(sys.argv[1])
buff=fp.read()
size_o=len(buff)
fp.close()
size_a=compress(buff)
print("the size was %d and it is %d\n"%(size_o,size_a))
fp=open("nfile.txt")
uncompress(fp.read())
#print ("the size was %d and it is %d"%(size_o,size_a))
