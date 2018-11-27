#!/bin/bash

FILENAME=

echo input filename:
read FILENAME

if [[ -c "$FILENAME" ]]; then
	cp $FILENAME /dev
else
	echo $FILENAME is not Character Device or not a file
fi
