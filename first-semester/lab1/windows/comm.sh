echo copy and del file
echo This is text1.txt>text1.txt
mkdir DIR1
cd DIR1
mkdir DIR2
cd DIR2
echo >textnew.txt
cd ..
cd ..
cp text1.txt DIR1/DIR2/textnew.txt
rm text1.txt
echo file has been copy and delete
read asd