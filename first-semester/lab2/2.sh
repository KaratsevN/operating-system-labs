s=$1
if test -e $s
then if test -r $s
then echo pravo na chtenie est
else echo prava na chtenie net
fi
if test -w $s
then echo pravo na zapis est
else echo prava na zapis net
fi
if test -x $s
then echo pravo na ispolzovanie est
else echo prava na ispolzovanie net
fi
else echo file not found
fi

