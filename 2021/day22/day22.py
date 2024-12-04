import re

#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

instructions = []

cube = [[[0 for i in range(101)] for j in range(101)] for k in range(101)]

for row in d:
  inst = row.split(' ')[0]
  rest = row.split(' ')[1]
  xs = [int(i) for i in (rest.split(',')[0])[2:].split("..")]
  ys = [int(i) for i in (rest.split(',')[1])[2:].split("..")]
  zs = [int(i) for i in (rest.split(',')[2])[2:].split("..")]
  for x in range(max(-51, xs[0]), min(51, xs[1])+1):
    for y in range(max(-51, ys[0]), min(51, ys[1])+1):
      for z in range(max(-51, zs[0]), min(51, zs[1])+1):
        if any([i > 50 or i < -50 for i in [x,y,z]]):
          continue
        if inst == "on":
          cube[x+50][y+50][z+50] = '1'
        else:
          cube[x+50][y+50][z+50] = '0'

total = 0
for i in range(101):
  for j in range(101):
    for k in range(101):
      if(int(cube[i][j][k])):
        total += 1

print(total)