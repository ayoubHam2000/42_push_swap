import re
import sys
import os

main_path = "."
if (len(sys.argv) > 1):
	main_path = sys.argv[1]

def proto_from_file(file):
	#print(f"/* {file} */")
	print("")
	file = open(file)
	data_types = "[a-zA-Z0-9_]+"
	function_name = "[a-zA-Z0-9_]+"
	regex = f"{data_types}[\t ]+[*]?{function_name}\(.*?\)"
	data = file.read()
	res = re.findall(regex, data)
	for i in res:
		print(f'{i};'.replace('\t', "\t"*1))

def proto_from_path(path):
	if os.path.isfile(path):
		proto_from_file(path)
	else:
		for x in os.listdir(path):
			f = os.path.join(path, x)
			if os.path.isfile(f):
				proto_from_file(f)
			elif os.path.isdir(f):
				proto_from_path(f)

proto_from_path(main_path)
