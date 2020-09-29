#!/bin/bash
ARGV=("$@")

up()
{
    cd ..
}

for i in {1..$ARGV[1]}
do
    echo Pulou 1 vez
    up
done








