f="per.txt"
n=`cat $f | wc -l`
i=1
while [ $i -le $n ]
do
	./push_swap.out `cat $f | head -$i | tail -1` | wc -l
	i=`echo $i + 1 | bc`
done