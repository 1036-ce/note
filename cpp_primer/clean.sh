#!/bin/bash

# 递归删除所有的二进制文件
function clean() {
	arr=`ls -l | awk 'NR>1 {print $NF}'`
	for i in $arr
	do
		# res=`file $i | grep dir`
		if [ $i == "trash" ]
		then 
			continue
		fi

		if [ "`file $i | grep dir`" ]
		then
			cd $i
			clean
		else
			if [ "`file $i | grep ELF`" ] || [ "`file $i | grep header`" ]
			then
				# mv $i ~/workspace/note/cpp_primer/trash
				rm $i
 			fi
		fi
	done
	cd ..
}

clean

