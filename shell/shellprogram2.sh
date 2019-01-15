if [ $# = 3]
then 
	case $2 in 
		+) let z=$1+$3;;
		-) let z=$1-$3;;
		/) let z=$1/$3;;
		x | X) z=$1*$3;;
	    *) echo " warning-$2 invalied operator ,only +,-,x，/" operator
