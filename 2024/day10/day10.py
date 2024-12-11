from copy import deepcopy

file = open("./input.txt")
d = file.read().split("\n")
d = [list(d[i]) for i in range(len(d))]

def dfs(i, j, seen):
  if i >= len(d) or i < 0 or j >= len(d[i]) or j < 0:
    return 0
  # if seen[i][j] == '.':
    # return 0
  if d[i][j] == '9':
    # seen[i][j] = '.'
    return 1
  curr = int(d[i][j])
  tmpTotal = 0
  if i+1 < len(d) and int(d[i+1][j]) - curr == 1:
    seen[i][j] = '.'
    tmpTotal += dfs(i+1, j, seen)
  if j+1 < len(d[i]) and int(d[i][j+1]) - curr == 1:
    seen[i][j] = '.'
    tmpTotal += dfs(i, j+1, seen)
  if i-1 >= 0 and int(d[i-1][j]) - curr == 1:
    seen[i][j] = '.'
    tmpTotal += dfs(i-1, j, seen)
  if j-1 >= 0 and int(d[i][j-1]) - curr == 1:
    seen[i][j] = '.'
    tmpTotal += dfs(i, j-1, seen)
  return tmpTotal

total = 0
for i in range(len(d)):
  for j in range(len(d[i])):
    if d[i][j] == '0':
      m = deepcopy(d)
      total += dfs(i,j,m)
print(total)