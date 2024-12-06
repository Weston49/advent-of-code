#Found a MUCH better file input boilerplate yippee
file = open("./input.txt")
d = file.read().split("\n")
d = [list(line) for line in d]
x = 0
y = 0

for i in range(len(d)):
  for j in range(len(d)):
    if d[i][j] == '^':
      x = i
      y = j


total = 0
p2total = 0

i = x
j = y

originX = i
originY = j

d_copy = [row[:] for row in d]

for z in range(len(d)):
  for p in range(len(d[z])):
    d = [row[:] for row in d_copy]
    if d[z][p] != '.':
      continue
    else:
      d[z][p] = '#'
      i = originX
      j = originY
      total = 0
      # print("==============================================================")
      while 1:
        # print(i, j)
        if total > (len(d)*len(d[0])):
          # print(d)
          p2total += 1
          break
        # for u in range(len(d)):
            # print(d[u])
        # print("=========================")
        if d[i][j] == '^':
          #move up
          if (i-1) < 0:
            break
          elif d[i-1][j] == '#':
            #turn 90deg
            d[i][j] = '>'
          elif d[i-1][j] == '.':
            d[i-1][j] = '^'
            d[i][j] = 'X'
            i = i-1
            total += 1
          elif d[i-1][j] == 'X':
            d[i-1][j] = '^'
            d[i][j] = 'X'
            i = i-1
            total += 1
        elif d[i][j] == '>':
          #move right
          if (j+1) > len(d)-1:
            break
          elif d[i][j+1] == '#':
            #turn 90deg
            d[i][j] = 'v'
          elif d[i][j+1] == '.':
            d[i][j+1] = '>'
            d[i][j] = 'X'
            j = j+1
            total += 1
          elif d[i][j+1] == 'X':
            d[i][j+1] = '>'
            d[i][j] = 'X'
            j = j+1
            total += 1
        elif d[i][j] == '<':
          #move left
          if (j-1) < 0:
            break
          elif d[i][j-1] == '#':
            #turn 90deg
            d[i][j] = '^'
          elif d[i][j-1] == '.':
            d[i][j-1] = '<'
            d[i][j] = 'X'
            j = j-1
            total += 1
          elif d[i][j-1] == 'X':
            d[i][j-1] = '<'
            d[i][j] = 'X'
            j = j-1
            total += 1
        elif d[i][j] == 'v':
          #move down
          if (i+1) > len(d[0])-1:
            break
          elif d[i+1][j] == '#':
            #turn 90deg
            d[i][j] = '<'
          elif d[i+1][j] == '.':
            d[i+1][j] = 'v'
            d[i][j] = 'X'
            i = i+1
            total += 1
          elif d[i+1][j] == 'X':
            d[i+1][j] = 'v'
            d[i][j] = 'X'
            i = i+1
            total += 1
        else:
          # print(d[i][j])
          # for u in range(len(d)):
            # print(d[u])
          break


total += 1
print(total)
print(p2total)