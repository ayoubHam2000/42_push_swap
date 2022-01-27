f="per_3.txt"
n=`cat $f | wc -l`
i=1
touch res.txt
echo -n "" > res.txt
while [ $i -le $n ]
do
	permutation=`cat $f | head -$i | tail -1`
	number=`./push_swap.exe $permutation | wc -l`
	number=`echo $number - 2 | bc`
	last=`./push_swap.exe $permutation | tail -1`
	echo "$i=$permutation=$number=$last" >> res.txt
	i=`echo $i + 1 | bc`
done
cat res.txt | sort -n -k 3 -t "="