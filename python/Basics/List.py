#!/usr/bin/env python2
#Date:12-5-18
import re
def cmd_executor(CMD,List):
    regex_insert = re.compile("insert (\d*) (\d*)")         
    if CMD.find("insert")!= -1:
        res=re.match(regex_insert,CMD)
        List.insert(int(res.group(2)),int(res.group(1)))
    elif CMD.find("print")!= -1:
        print(List)
    elif CMD.find("append")!=  -1:
        List.append(int(CMD.split(' ')[1]))
    elif CMD.find("sort")!= -1:
        List.sort()
    elif CMD.find("reverse")!= -1:
        List.reverse()
    elif CMD.find("pop")!= -1:
        List.pop()
    elif CMD.find("remove")!= -1:
        List.remove(int(CMD.split(' ')[1]))
    else:
        print("you have entered an unsupported command !")
if __name__ == '__main__':
    N = int(raw_input("please enter no of commands to be entered:"))
    List = []
    for i in xrange(N):
        cmd = raw_input("please enter a command:")
        cmd_executor(cmd,List)

'''def cmd_executor(self,CMD,List):
    regex_insert = re.compile("insert (/d) (/d)")

    if CMD.find("insert")!= -1:
        res=re.match(regex_append,CMD)
        List.insert(re.group(1),res.group(2))
    elif CMD.find("print")!= -1:
        print(List)
    elif CMD.find("append")!=  -1:
        List.append(int(CMD.split(' ')[1]))
    elif CMD.find("sort")!= -1:
        List.sort()
    elif CMD.find("reverse")!= -1:
        List.reverse()
    elif CMD.find("pop")!= -1:
        List.pop()
    elif CMD.find("remove")!= -1:
        List.remove(int(CMD.split(' ')[1]))
'''
