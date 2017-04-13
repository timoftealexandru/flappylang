#!/bin/sh
#Created by MihaiSandor on 18-Mar-2017

p=python
if (( p ))
    f=flappy.py
    $p $f "$1" # check first argument
then
    exit;
fi

p3=python3
if (( p3 ))
    f=flappylang.py
    $p3 $f "$1" # check first argument
then
    exit;
fi

if ! (( p && p3 ))
then
    cd bin && python3 -W ignore flappy_calc.py # Run REPL & Calculator
fi
