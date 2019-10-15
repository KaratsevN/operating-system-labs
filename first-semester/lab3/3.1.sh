df > report.txt
ls -h -s report.txt

if test -r report.txt
then
echo 'File is available for reading'
else
echo 'File is not available for reading'
fi
if test -w report.txt
then
echo 'File is available for writing'
else
echo 'File is not available for writing'
fi
if test -x report.txt
then
echo 'File is available for using'
else
echo 'File is not available for using'
fi
read 111


