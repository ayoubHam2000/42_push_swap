import random

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
	largest_end = lists[0]
	for item in lists:
		end = item[-1]
		if (end <= n and end > largest_end[-1]):
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
	new_list = [item for item in lists if len(item) == max_length]
	return new_list

def LICS(arr):
	lists = []
	a = arr + arr
	for i in range (0, len(arr)):
		sub = a[0 + i:len(arr) + i]
		lists.extend(LIS(sub))
	max_length = max([len(item) for item in lists])
	new_list = [item for item in lists if len(item) == max_length]
	return new_list

n = 100
a = [i for i in range(0, n)]
m = 0
for _ in range(0, 1000):
	random.shuffle(a)
	r = LICS(a[::-1])
	m = m + len(r[0])
print(m / 1000)