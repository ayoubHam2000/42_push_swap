from ast import arg
import sys

args = sys.argv
print("[", end = "")
i = 0
for i in range(1, len(sys.argv)):
	print(f'"{sys.argv[i]}", ', end = "")
print("]")