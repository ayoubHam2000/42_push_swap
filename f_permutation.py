import itertools

for i in list(itertools.permutations([1, 2, 3, 4, 5])):
	print(f"{i}".replace("(", "").replace(",", "").replace(")", ""))