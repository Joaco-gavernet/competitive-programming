#!/bin/bash

# Check if the user passed an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <number>"
  exit 1
fi

# Store the argument in a variable
NUMBER=$1

# Execute the command with the given number
./A2.exe < secret/test$NUMBER.in && cat secret/test$NUMBER.ans
