#!/bin/bash

for f in $(find ./ -name *.cpp)
do
    cat $f | grep -v "^#include"
done
