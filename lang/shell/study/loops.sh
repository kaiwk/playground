#!/usr/bin/env bash

function while_loop {
    number=0
    while [ $number -lt 10 ]; do
        echo "number=$number"
        number=$((number+1))
    done
}

function until_loop {
    number=0
    until [ $number -ge 10 ]; do
        echo "number=$number"
        number=$((number+1))
    done
}

function main {
    until_loop
}

main
