echo 'Input full way of directory: '
read a
cd /home/`whoami`
cd $a
ls -i -l -h > 3.2.txt
sort -n `pwd`/3.2.txt > `pwd`/temp.txt
cat `pwd`/temp.txt > `pwd`/3.2.txt
rm temp.txt
chmod 777 `pwd`/3.2.txt

ln `pwd`/3.2.txt /home/`whoami`/5/3.2.txt
ln -s `pwd`/3.2.txt /home/`whoami`/Desktop/3.2.txt
read dasdsadsa
