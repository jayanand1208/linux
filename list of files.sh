#!/bin/bash

# Loop through all arguments
for arg in "$@"
do
    # Check if the argument is a file
    if [ -f "$arg" ]
    then
        echo "$arg is a file and has $(wc -l < "$arg") lines"
    # Check if the argument is a directory
    elif [ -d "$arg" ]
    then
        echo "$arg is a directory"
    # If the argument is neither a file nor a directory, report an error
    else
        echo "$arg is not a file or directory"
    fi
done

