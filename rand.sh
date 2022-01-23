t=`seq 1 $1 | sort -R | tr '\n' ' '`
n=`./push_swap.out $t | wc -l`
echo $t
echo $n