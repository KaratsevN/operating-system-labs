echo 'Input full way of directory: '
read way
cd $way
ls -i -l -h >3.2.txt
sort -n `pwd`/3.2.txt > `pwd`/temp.txt
cat `pwd`/temp.txt > `pwd`/3.2.txt
rm temp.txt
chmod 777 `pwd`/3.2.txt


ln `pwd`/3.2.txt /home/`whoami`/3.2.txt
#Desktop -- 'Рабочий стол'
ln -s `pwd`/3.2.txt /home/`whoami`/3.2symbol.txt
read asd