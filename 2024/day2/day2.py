#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

#Room for helper functions
def is_row_safe(row):
  safe = True
  inc = int(row[0]) < int(row[1])
  for i in range(len(row)-1):
    if(int(row[i]) == int(row[i+1])):
      return False
    if abs(int(row[i]) - int(row[i+1])) > 3:
      return False
    if inc and int(row[i]) > int(row[i+1]):
      return False
    if not inc and int(row[i]) < int(row[i+1]):
      return False
  return True

#Room for cleaning up input
levels = []
for i in range(len(d)):
  levels.append(d[i].split())

#Part 1
total = 0

for row in levels:
  if is_row_safe(row):
    total += 1
    
print("Part 1: ", total)

#Part 2
total = 0

for row in levels:
  for i in range(len(row)):
    new_row = row[:i] + row[i+1:]
    if is_row_safe(new_row):
      total += 1
      break



print("Part 2: ", total)