#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

d = [list(line.strip()) for line in d if line.strip()]

def is_xmas(i, j, dir):
  directions = [
    [-1, 0], 
    [-1, 1], 
    [0, 1],  
    [1, 1],  
    [1, 0],  
    [1, -1], 
    [0, -1], 
    [-1, -1] 
  ]

  if (i + (directions[dir][0]*3)) >= len(d) or (j + (directions[dir][1]*3) >= len(d[i])) or ((i + (directions[dir][0]*3)) < 0) or ((j + (directions[dir][1]*3)) < 0):
    return False

  if d[i+directions[dir][0]][j+directions[dir][1]] == 'M':
    if d[i+(directions[dir][0]*2)][j+(directions[dir][1]*2)] == 'A':
      if d[i+(directions[dir][0]*3)][j+(directions[dir][1]*3)] == 'S':
        # print(f"Found XMAS at ({i}, {j}) in direction {dir}")
        return True
  return False


def is_x_mas(i, j):
  if (i+1) >= len(d) or (j+1) >= len(d[i]) or ((i-1) < 0) or ((j-1) < 0):
    return False

  if (d[i+1][j+1] == 'M' and d[i-1][j-1] == 'S') or (d[i+1][j+1] == 'S' and d[i-1][j-1] == 'M'):
    if (d[i+1][j-1] == 'M' and d[i-1][j+1] == 'S') or (d[i+1][j-1] == 'S' and d[i-1][j+1] == 'M'):
      return True
  return False

total = 0

for i in range(len(d)):
  for j in range(len(d[i])):
    if d[i][j] == 'X':
      for k in range(8):
        if is_xmas(i, j, k) == True:
          total += 1
print("part 1: ", total)

total = 0
for i in range(len(d)):
  for j in range(len(d[i])):
    if d[i][j] == 'A':
      if is_x_mas(i, j) == True:
        total += 1
print("part 2: ", total)