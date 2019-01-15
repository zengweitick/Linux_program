#!/bin/bash 
clear
select item in Continue Finish
do 
	case "$item" in
		Continue);;
		Finish)break;;
		*)echo "wrong choice ! please aelect again!";;
	esac
done	
