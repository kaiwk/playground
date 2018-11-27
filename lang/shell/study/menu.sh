#!/usr/bin/env bash

function press_enter {
    echo ""
    echo -n "Press Enter to continue."
    read
    clear
}

function show_menu {
    selection=
    until [ "$selection" = "0" ]; do
        echo ""
        echo "PROGRAM MENU"
        echo "1 - display free disk space"
        echo "2 - display free memory"
        echo ""
        echo "0 - exit program"
        echo ""
        echo -n "Enter selection: "
        read selection
        echo ""
        case $selection in
            1 ) df ; press_enter ;;
            2 ) free ; press_enter ;;
            0 ) exit ;;
            * ) echo "Please enter 1, 2, or 0"; press_enter
        esac
    done
}

function main {
    show_menu
}

main
