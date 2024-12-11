#Found a MUCH better file input boilerplate yippee
file = open("./input.txt")
d = file.read().split("\n")
d = [list(line) for line in d]

anits = [[0 for _ in range(len(d[0]))] for _ in range(len(d))]

total = 0
for i in range(len(d)):
  for j in range(len(d[i])):
    if d[i][j] == '.' or d[i][j] == '#':
      continue
    else:
      c = d[i][j]
      for k in range(len(d)):
        for l in range(len(d[k])):
          if k == i and l == j:
            continue
          if d[k][l] == c:
            kDiff = k - i
            lDiff = l - j
            for z in range(len(d)*2):
              tmpkDiff = kDiff * (z)
              tmplDiff = lDiff * (z)
              if (k+tmpkDiff) >= 0 and (k+tmpkDiff) < len(d):
                if (l+tmplDiff) >= 0 and (l+tmplDiff) < len(d[k]):
                  if anits[k+tmpkDiff][l+tmplDiff] != 1:
                    anits[k+tmpkDiff][l+tmplDiff] = 1
                    # d[k+tmpkDiff][l+tmplDiff] = '#'
                    total += 1
# for i in range(len(d)):
#   print(d[i])
print(total)

# extra stuff lol
for i in range(len(d)):
  for j in range(len(d[i])):
    if anits[i][j] == 1 and d[i][j] == '.':
      d[i][j] = '#'

for i in range(len(d)):
  print(''.join(d[i]))