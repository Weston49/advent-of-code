#Found a MUCH better file input boilerplate yippee
file = open("./input.txt")
d = file.read().split("\n")

def can_be_solved(row, total):
  if(len(row) == 2):
    if int(row[0]) * int (row[1]) == int(total) or int(row[0]) + int (row[1]) == int(total) or int(str(row[0]) + str(row[1])) == int(total):
      return True
    else:
      return False
  else:
    tmpRow = row.copy()
    tmpRow[1] = int(tmpRow[0]) * int(tmpRow[1])
    tmpRow = tmpRow[1:]
    if can_be_solved(tmpRow, total):
      return True
    tmpRow = row.copy()
    tmpRow[1] = int(tmpRow[0]) + int(tmpRow[1])
    tmpRow = tmpRow[1:]
    if can_be_solved(tmpRow, total):
      return True
    tmpRow = row.copy()
    tmpRow[1] = str(tmpRow[0]) + str(tmpRow[1])
    tmpRow = tmpRow[1:]
    if can_be_solved(tmpRow, total):
      return True
    return False

total = 0

for i in range(len(d)):
  tmp = d[i].split(':')
  tmpTotal = tmp[0]
  tmp = tmp[1].split(" ")
  tmp = tmp[1:]
  if can_be_solved(tmp, tmpTotal):
    total += int(d[i].split(':')[0])

print(total)