#!/bin/bash

PATH=/media/07E8-0003/GPX/
TMPNAME=$RANDOM
while [ -e $PATH$TMPNAME.gpx ]; do
	TMPNAME=$TMPNAME$RANDOM 
done
TMPNAME=$TMPNAME.gpx
/usr/bin/gpsbabel -i geo -f "$1" -o gpx -F "$PATH$TMPNAME"
/bin/rm "$1"
/bin/sed -i 's/<name>/<x>/g' "$PATH$TMPNAME"
/bin/sed -i 's/<\/name>/<\/x>/g' "$PATH$TMPNAME"
/bin/sed -i 's/<cmt>/<name>/g' "$PATH$TMPNAME"
/bin/sed -i 's/<\/cmt>/<\/name>/g' "$PATH$TMPNAME"
/bin/sed -i 's/<x>/<cmt>/g' "$PATH$TMPNAME"
/bin/sed -i 's/<\/x>/<\/cmt>/g' "$PATH$TMPNAME"
