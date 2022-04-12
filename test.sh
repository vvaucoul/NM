#!/bin/bash
make
for var in "$@"
do
    printf "\e[1;37mTest with \e[1;36m$var\e[1;37m:\e[0m\n"
    ./ft_nm $var > 01
    nm $var > 02
    diff 01 02 > /dev/null
    res=$(echo $?)
        if [ "$res" == 0 ]
        then
            printf "\e[32mSUCCESS\e[0m\n"
        else
            printf "\e[31mFAILURE\e[0m\n"
        fi
    rm 01 02
done