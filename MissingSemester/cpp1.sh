echo "Starting at time of $(date)"
echo "Running program $0 with $# agruments with pid $$"
for file in "$@"; do
	grep "bits/stdc++.h" "$file">./CPP.txt
if [[ $? -ne 0 ]] ; then 
	echo "File $file does not have any cpp,add one"
	echo "# cpp" >>"$file"
fi
done
