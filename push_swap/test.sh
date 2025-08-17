#!/bin/bash

for args in \
    "1 2 3" \
    "3 2 1" \
    "1 2 2" \
    "1 a 3" \
    "2147483647 -2147483648 0" \
    "1 2 2147483648" \
    ""; do
  echo "./push_swap $args"
  ./push_swap $args
  echo "-----"
done