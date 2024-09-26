#!/bin/bash

# Check if the user passed an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <number>"
  exit 1
fi

# Store the argument in a variable
NUMBER=$1

# Execute the command with the given number
echo "Your answers: "
./a.exe < secret/input/C_$NUMBER

# echo ""
# echo "Correct answers: "
# cat secret/output/C_$NUMBER
