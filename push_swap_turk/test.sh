#!/bin/bash

for args in \
    "1 2 3" \
    "3 2 1" \
    "2 1 3" \
    "5 4 3 2 1" \
    "1 3 2 6 5 8 7 9 4" \
    "10 9 8 7 6 5 4 3 2 1" \
    "2147483647 -2147483648 0" \
    "42" \
    "  1   2   3  " \
    "" \
    "1 2 2" \
    "1 a 3" \
    "1 2 2147483648" \
    "   " \
    "1 2 03" \
    "1 --2 3" \
    "1 2 3b" \
    "1 2 + 3" \
    "1 2 - 3" \
    "1 2 +3" \
    "1 2 -3" \
    "1 2 3 3" \
    "1 2 3" 3 \
    ; do
  echo "./push_swap $args"
  ./push_swap $args
  echo "-----"
done

#to test the requirements for the project validation also with the memory leaks, without it just delete valgrind and also change the range after seq + amount after the shuffle
#ARG=$(seq -1000 1000 | shuf -n 100 | tr '\n' ' ')
#valgrind ./push_swap $ARG | wc -l
