f="per_3.txt"
n=`cat $f | wc -l`
i=1
touch res.txt
echo -n "" > res.txt
while [ $i -le $n ]
do
	permutation=`cat $f | head -$i | tail -1`
	number=`./push_swap.out $permutation | wc -l`
	number=`echo $number - 1 | bc`
	echo "$i=$permutation=$number" >> res.txt
	i=`echo $i + 1 | bc`
done
cat res.txt | sort -n -k 3 -t "="