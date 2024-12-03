#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

#Part 1
total = 0
list1,list2 = [],[]

for line in d:
    list1.append(line.split()[0])
    list2.append(line.split()[1])

list1.sort()
list2.sort()
for i in range(len(list1)):
    total += abs(int(list1[i]) - int(list2[i]))

print("Part 1: ", total)

#Part 2
total = 0
for i in range(len(list1)):
    total += int(list1[i]) * int(list2.count(list1[i]))

print("Part 2: ", total)
