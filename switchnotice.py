#!/usr/bin/env python
# (c) Jan Dlabal, 2011
# Switches notice at the beginning of a file in all *.[ch] and *.[ch]pp files
# Assumes the notice is a block of lines starting with /*
# Assumes the notice is ended when the first line not starting with /* is encountered
#
# The program first reads the file, then drops all lines which start with /* until a line not satisfying this is encountered
# Then it writes the new notice into the file, and all original lines starting with the first not beginning with /*
#
# Make sure you understand the above to avoid surprises.

import os
from sys import argv


class PyWalk():
    def __init__(self,d,action,daction=None):
        self.d = d
        self.action = action
        self.daction = daction

    def walk(self,path=None):
        if not path:
            path = self.d
        if os.path.isdir(path):
            l = os.listdir(path)
            if path != self.d and self.daction:
                self.daction(path)
            for el in l:
                self.walk(path+"/"+el)
        else:
            self.action(path)

def replacenotice(file):
    global newnotice
    if file.endswith(".c") or file.endswith(".h") or file.endswith(".cpp") or file.endswith(".hpp"):
        with open(file,"r") as f:
            lines = f.readlines()
        with open(file,"w") as f:
            f.write(newnotice)
            if newnotice[-1]!='\n':
                f.write("\n")
            pastnotice = False
            for x in lines:
                if x.startswith("/*") and not pastnotice:
                    pass
                else:
                    pastnotice = True
                    f.write(x)

newnotice = ""
if len(argv)!=3:
    print "Usage : "+argv[0]+" NOTICEFILE PATH"
else:
    with open(argv[1],"r") as f:
        newnotice = "".join(f.readlines())
    replacer = PyWalk(argv[2],replacenotice)
    replacer.walk()
