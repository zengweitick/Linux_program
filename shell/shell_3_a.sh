#!/bin/bash 
for x in 1 2 3
do 
	 echo Before $x
	 for y in a b c 
	 do 
		 echo Before $y
		 continue 1
		 echo After $y
	 done
	 echo After $x
 done
