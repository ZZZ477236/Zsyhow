#!/bin/bash
echo "starttime $(date)"
echo "run $0 with $# pid $$"
for file in "$@";
do
	grep "foobar" "$file" > ./foobar 2> ./foobar
	if [[ "$?" -ne 0 ]]; then
		echo "no foobar,add one"
		echo "foobar" >> "$file"
	fi
done

