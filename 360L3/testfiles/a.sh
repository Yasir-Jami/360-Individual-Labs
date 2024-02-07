#!/bin/bash
PATH= ~/scripts
file= "$1"
interface="$2"

address= $(cat "$PATH/$1" |grep $2 -A 2 |grep ether)

md5=$1 

echo "Data used to generated ID: `hostname`\\$address"

echo "The generated code: $md5"

#!/bin/bash

var=$(grep "en1" -A 2 $1 |grep -o "[0-9][0-9]:\w\w:\w\w:\w\w:\w\w:\w\w")

md5=$1 

echo "Data used to generated ID: `hostname`\\$var"

echo "The generated code: $md5"
