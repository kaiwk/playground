#!/usr/bin/env bash

echo -n "Enter you string > "
if read -t 3 -s text; then
    echo "Great! you made it in time."
else
    echo "Sorry, you are too slow."
fi

echo "You entered: $text"
