#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

rules = []
insts = []
r = True

for line in d:
  if line == "\n":
    r = False
    continue
  if r:
    rules.append(line)
  else:
    insts.append(line)

rs = []

for rule in rules:
  rs.append([int(rule[0:2]),int(rule[3:])])

for i in range(len(insts)):
  insts[i] = insts[i].split(",")
  for j in range(len(insts[i])):
    insts[i][j] = int(insts[i][j])

def is_row_valid(row, rules):
  for i in range(len(row)):
    for j in range(0,i):
      tmp = []
      tmp.append(row[i])
      tmp.append(row[j])
      if tmp in rules:
        return False
  return True

def is_row_valid_changed(row, rules):
  changed = False
  for i in range(len(row)):
    for j in range(0,i):
      tmp = []
      tmp.append(row[i])
      tmp.append(row[j])
      if tmp in rules:
        tmpVal = row[i]
        row[i] = row[j]
        row[j] = tmpVal
        changed = True
  return changed

#part 1
total = 0
for row in insts:
  if is_row_valid(row, rs):
    total += row[int(len(row)/2)]
print("Part 1: ", total)

#part 2
total = 0
for row in insts:
  if is_row_valid_changed(row, rs):
    total += row[int(len(row)/2)]
print("Part 2: ", total)