cd /home/`whoami`

echo 'Input name of user: '
read c

if grep "^$c" /etc/passwd > temp.txt
then
	echo "$c is registered in the system."
	who -u > temp2.txt
	if grep "^$c" temp2.txt > temp.txt
	then
		echo "$c is working."
	else
		echo "$c is not working."
	fi
	rm temp2.txt
else
	echo "$c is not registered in the system"
fi

sed 's/\([^:]*\):[^:]*:\([^:]*\):[^:]*:[^:]*:\([^:]*\):.*/\2\t\1\t\3/' /etc/passwd > temp.txt
sort -h -r temp.txt

rm temp.txt
read t
