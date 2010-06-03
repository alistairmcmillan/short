#!/usr/bin/env python
# A simple python class to walk through a directory structure.
# You can provide the action() and daction() functions (daction() is optional) and they will be called respectively for each file in the directory structure, and for each directory in the structure, except the base of the structure (ie., the parameter d).
# Feel free to reuse this, it is licensed under the GNU GPL v3 License.
# Written by Jan Dlabal, 2010.
# http://houbysoft.com/


import os


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
