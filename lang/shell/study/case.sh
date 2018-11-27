#!/usr/bin/env bash

function check_number {
    echo -n "Enter a number between 1 and 3 inclusive > "
    read character
    case $character in
        1 ) echo "You entered one."
            ;;
        2 ) echo "You entered two."
            ;;
        3 ) echo "You entered three."
            ;;
        * ) echo "You did not enter a number"
            echo "between 1 and 3."
    esac
}

function check_letter {
    echo -n "Type a digit or a letter > "
    read character
    case $character in
        # Check for letters
        [a-z] | [A-Z] ) echo "You typed the letter $character"
                        ;;

        # Check for digits
        [0-9] )     echo "You typed the digit $character"
                    ;;

        # Check for anything else
        * )         echo "You did not type a letter or a digit"
    esac
}

function main {
    # check_number
    check_letter
}

main
