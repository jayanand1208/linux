echo "enter the filename"
read f
echo "enter the word"
read w
echo "file before removing the word:$w"
cat $f
grep -v -i $w $f>t
mv t $f
echo "file after deleting the word:$w"
cat $f
