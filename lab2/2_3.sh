fun1(){
if who -q | grep -w $name > null
then echo user is content
else echo user is not content
fi
rm null
}
fun2(){
if who -qu | grep -w $name > null
then echo user is content now
else echo user is not content now
fi
rm null
}
fun3(){
cat /etc/passwd | sort -rt: +2n -3
}
fun4(){
read name
}
while true
do
echo 1 - find user
echo 2 - work user
echo 3 - get list of registered users
echo 4 - new username
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

