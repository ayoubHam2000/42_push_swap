import random
import sys

def case1(lists, n):
	lists.append([n])

def case2(lists, n):
	largest = lists[0]
	for item in lists:
		if len(item) > len(largest):
			largest = item
	lists.append(largest + [n])

def case3(lists, n):
	#largest end that is smaller than n
	largest_end = None
	for item in lists:
		end = item[-1]
		if (end < n and not largest_end):
			largest_end = item
		elif (end < n and end > largest_end[-1]):
			largest_end = item
	new_item = largest_end + [n]
	new_list = [item for item in lists if len(item) != len(new_item)]
	new_list.append(new_item)
	lists.clear()
	lists.extend(new_list)

def	is_the_smallest(lists, n):
	for item in lists:
		if n > item[-1]:
			return (0)
	return (1)

def is_the_largest(lists, n):
	for item in lists:
		if n < item[-1]:
			return (0)
	return (1)

def LIS(arr):
	lists = []
	for n in arr:
		if (is_the_smallest(lists, n)):
			case1(lists, n)
		elif (is_the_largest(lists, n)):
			case2(lists, n)
		else:
			case3(lists, n)
	max_length = max([len(item) for item in lists])
	lists = [item for item in lists if len(item) == max_length]
	return lists

def LICS(arr):
	lists = []
	a = arr + arr
	for i in range (0, len(arr)):
		sub = a[0 + i:len(arr) + i]
		lists.extend(LIS(sub))
	max_length = max([len(item) for item in lists])
	new_list = [item for item in lists if len(item) == max_length]
	return new_list

# arr = []
# for i in range(1, len(sys.argv)):
# 	arr.append(int(sys.argv[i]))
# r = LIS(arr[::-1])
# for item in r:
# 	print(item[::-1])
# 	print(len(item))
# 	print("================")

n = 100
a = [i for i in range(0, n)]
m = 0
i = 0
for _ in range(0, 1000):
	random.shuffle(a)
	r = LICS(a[::-1])
	m = m + len(r[0])
	i = i + 1
	print(m / i)