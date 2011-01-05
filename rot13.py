#!/usr/bin/env python
# Simple rot13 implementation


from sys import argv


def rot13(str):
  res = ""
  for x in str:
    y = ord(x)-96
    if y<=13 and y>=0:
      res+= chr(y+96+13)
    elif y<=26 and y>=0:
      res+= chr(y+96-13)
    else:
      res+= chr(y+96)
  print res


if len(argv)==2:
  rot13(argv[1])
else:
  print "Nothing to ROT13!"
