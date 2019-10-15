fun1(){
df > log1.txt
}
fun2(){
ls -ogh log1.txt
}
while true
do
echo 1 - create log
echo 2 - write i-node information
echo 3 - exit
read f
case $f in 
1 )
fun1
;;
2 )
fun2
;;
3 ) 
exit
;;
esac
done

