#!/usr/bin/env bash

exist_file() {
    if [ -f ~/.zshrc ];
    then echo "You have a .zshrc file in you home directory."
    else echo "Yikes! You have no .zshrc file!"
    fi
}

is_root() {
    if [ $(id -u) = "0" ]; then
        echo "superuser."
    else
        echo "normal user."
    fi
}

must_root() {
    if [ $(id -u) != "0" ]; then
        echo "You must be root user to execute this script!" >&2
        exit 1
    fi
}


# turn tracing on, set +x turn tracing off.
set -x
number=1
function trouble {
    if [ "$number" = "1" ]; then
        echo "Number equals 1"
    else
        echo "Number does not equal 1"
    fi
}

function main {
    trouble
}

main
