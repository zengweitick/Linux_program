#include <stdio.h>#!/bin/bash 

sum=0
for((i=0;i<100;i++))
do 
	let sum+=$i
done
echo "$sum"

