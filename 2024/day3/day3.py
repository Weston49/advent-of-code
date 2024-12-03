import re

#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

d = ''.join(d)

#part 1
total = 0
x = re.findall(r"mul\([0-9]+,[0-9]+\)", d)
for i in range(len(x)):
  tmpStr = x[i][4:-1]
  tmpStr = tmpStr.replace(",", " ")
  total += int(tmpStr.split()[0]) * int(tmpStr.split()[1])
print("Part 1: ", total)

#stripping input for part 2
stripped_input = []
tmpStr = d
tmp = []

while 1:
  tmp = re.split(r"don't\(\)", tmpStr, maxsplit=1)
  stripped_input.append(tmp[0])
  tmpStr = tmp[1]
  tmp = re.split(r"do\(\)", tmpStr, maxsplit=1)
  if len(tmp) <= 1:
    break
  tmpStr = tmp[1]

tmpStr = ""

#part 2
total = 0
for line in stripped_input:
  x = re.findall(r"mul\([0-9]+,[0-9]+\)", line)
  for i in range(len(x)):
    tmpStr = x[i][4:-1]
    tmpStr = tmpStr.replace(",", " ")
    total += int(tmpStr.split()[0]) * int(tmpStr.split()[1])
print("Part 2: ", total)

