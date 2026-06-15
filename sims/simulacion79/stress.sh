#!/usr/bin/env bash
shopt -s expand_aliases
source ~/.bashrc

rm input_*.txt output_main_*.txt output_broute_*.txt

# icpc gen
# icpc G
# icpc broute

CXX=clang++
CXXFLAGS="-std=c++17 -O2 -Wall -Wextra"

$CXX $CXXFLAGS gen.cpp -o gen
$CXX $CXXFLAGS G.cpp -o G
$CXX $CXXFLAGS broute.cpp -o broute

i=1
while true; do
	echo "Testing: $i"
	./gen $i > input_$i.txt
    ./G < input_$i.txt > output_main_$i.txt
    ./broute < input_$i.txt > output_broute_$i.txt
    python3 checker.py output_main_$i.txt output_broute_$i.txt
    status=$?
    if [ $status -eq 1 ]; then
        echo "Wrong answer on test $i"
        break
    fi

    i=$((i + 1))
    sleep 1
done