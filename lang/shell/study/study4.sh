#!/usr/bin/env sh

if [ $(id -u) != "0"  ]; then
    echo "You must be the superuser to run this script" >&2
    exit 1
else
    if [[ -f .bash_profile ]]; then
        echo ".bash_profile exsit."
    else
        echo ".bash_profile doesn't exsit."
    fi
fi
