#!/bin/bash 
sum=0
for((i=1;i<=100;i++))
do 
	let sum+=$i
done
echo $sum 
