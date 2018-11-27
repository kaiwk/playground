#!/usr/bin/env bash

# echo "positional parameters"
# echo '$0 '= $0
# echo '$1 '= $1
# echo '$2 '= $2
# echo '$3 '= $3

echo "You start with $# positional parameters"

# Loop until all parameters are used up
while [ "$1" != "" ]; do
    echo "Parameter 1 equals $1"
    echo "You now have $# positional parameters"

    # Shift all the parameters down by one
    shift

done
