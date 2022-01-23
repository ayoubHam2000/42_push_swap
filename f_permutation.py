import itertools

for i in list(itertools.permutations([1, 2, 3])):
	print(f"{i}".replace("(", "").replace(",", "").replace(")", ""))