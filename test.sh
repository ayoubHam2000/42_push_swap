i=0
e=50
echo -n "" > log.txt
while [ $i -le $e ]
do
	t=`seq 1 500 | sort -R`
	n=`./push_swap.exe $t | wc -l`
	echo $n >> log.txt
	i=`echo $i + 1 | bc`
	echo $i
done
cat log.txt | sort -n
