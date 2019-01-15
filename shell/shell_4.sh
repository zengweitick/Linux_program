#!/bin/bash 
fact(){
	if [ "$1" -eq "0"]; then 
		echo 1
	else 
		i=`expr $1 -1`
		j=`fact $i`
		k=`expr $1 \* $j`
		echo $k
	fi

}
while :
do 
	echo -n "Enter a number"
	read x
	fact $x
done
