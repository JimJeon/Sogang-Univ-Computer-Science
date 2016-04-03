#!/bin/bash

function change_name
{
    for i in *
    do
        newFile=`echo $i | tr "A-Za-z" "a-zA-Z"`
        if [ $i == $newFile ]
        then
            continue
        fi
        mv $i $newFile
    done
}

echo "working directory:"
read dir

if [ -n "$dir" ]
then
    if [ ! -d "$dir" ]
    then
        echo "ERROR: no such file or directory"
        exit 1
    elif [ ! -w "$dir" ]
    then
        echo "ERROR: permission denied"
        exit 1
    else
        cd $dir
        change_name $dir
    fi
else
    change_name .
fi
