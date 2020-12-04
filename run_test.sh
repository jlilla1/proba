#!/bin/bash

IFS=$'\n'


if test -f out_res.txt; do
	rm out_res.txt
done


for i in 'cat inputs.txt'; do
	echo "$i" | main >> out_res.txt
done



