#!/bin/bash

if [ -n "$3" ]; then
    GPXPATH="$3/"
else
    GPXPATH=/mnt/5/GPX/
fi

TMPNAME=$RANDOM

while [ -e $GPXPATH$TMPNAME.gpx ]; do
    TMPNAME=$TMPNAME$RANDOM
done

TMPNAME=$TMPNAME.gpx
echo $TMPNAME

gpsbabel -i geo -f "$1" -o gpx -F "$GPXPATH$TMPNAME"
rm "$1"
sed -i 's/<name>/<x>/g' "$GPXPATH$TMPNAME"
sed -i 's/<\/name>/<\/x>/g' "$GPXPATH$TMPNAME"
sed -i 's/<cmt>/<name>/g' "$GPXPATH$TMPNAME"
sed -i 's/<\/cmt>/<\/name>/g' "$GPXPATH$TMPNAME"
sed -i 's/<x>/<cmt>/g' "$GPXPATH$TMPNAME"
sed -i 's/<\/x>/<\/cmt>/g' "$GPXPATH$TMPNAME"

if [ -n "$2" ]; then
    sed -i "s/<\/desc>/ $2<\/desc>/g" "$GPXPATH$TMPNAME"
fi
