import random
import sys

if len(sys.argv) <= 1:
	exit()
a = [i for i in range(0, int(sys.argv[1]))]
random.shuffle(a)
for item in a:
	print(item , end = " ")