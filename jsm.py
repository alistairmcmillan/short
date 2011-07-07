#!/usr/bin/env python2
# JSM -- just send mail
# simple script to Just Send Mail (jsm)
# (c) Jan Dlabal, 2011.
# http://houbysoft.com/
# Provided under the GNU GPL v3 License.

from sys import argv, stdin
from email.mime.text import MIMEText
import smtplib
from DNS.lazy import mxlookup

if len(argv) != 4 and len(argv) != 5:
  print("Usage : " + argv[0] +" FROM TO SUBJECT [MESSAGE]")
  print(" FROM is the email address to send from")
  print(" TO is the email address to send to")
  print(" SUBJECT is the email's subject")
  print(" MESSAGE is the email's message. If not specified, it is read from stdin.")
  print("\nThis program is (c) Jan Dlabal, 2011, and is available under the terms of the GNU GPL v3 License.")
else:
  if len(argv) == 5:
    msg = MIMEText(argv[4])
  else:
    msg = MIMEText(stdin.read())
  msg['Subject'] = argv[3]
  msg['To'] = argv[2]
  msg['From'] = argv[1]
  try:
    server = mxlookup(argv[2].split('@')[1])[0][1]
  except:
    print("Error : Could not get an MX record.")
    exit(1)
  print("Connecting to " + server)
  s = smtplib.SMTP(server)
  d = s.sendmail(argv[1], [argv[2]], msg.as_string())
  if len(d) == 0:
    print("Email sent successfully")
  else:
    print("Error occured while sending : " + repr(d))
  s.quit()
  exit(0)

