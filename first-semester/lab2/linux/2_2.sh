fun1(){
ls -G -iog $name > log.txt
sort -i log.txt > log2.txt
rm log.txt
}
fun2(){
chmod 777 log2.txt
}
fun3(){
sudo ln -f log2.txt ~/
sudo ln -sf ~/Downloads/karatsev/log2.txt ~/Desktop/log2.txt
}
fun4(){
read name
}
while true
do
echo 1 - create log
echo 2 - opens full rights
echo 3 - creates links
echo 4 - new directory name
echo 5 - exit
read f
case $f in 
1 )
fun1
;;
2 )
fun2
;;
3 ) 
fun3
;;
4 )
fun4
;;
5 ) 
exit
;;
esac
done

