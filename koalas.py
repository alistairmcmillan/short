#!/usr/bin/env python

from os import system
from math import floor
from random import random
from time import sleep

def randompoint():
    i = floor(random() * 128)
    j = floor(random() * 128)
    x = 360
    dx = 490.0 / 128.0
    dy = 515.0 / 128.0
    if i != 0:
      x = int(360 + i * dx)
    y = 175
    if j != 0:
      y = int(175 + j * dy)
#x = floor(random() * 490) + 360
#y = floor(random() * 515) + 175
    system("~/Downloads/click -x " + repr(x) + " -y " + repr(y) +" -q")

print "GET READY"
sleep(2)
for x in range(0,2000):
    randompoint()

