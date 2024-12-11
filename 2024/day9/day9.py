#Found a MUCH better file input boilerplate yippee
file = open("./input.txt")
d = file.read().split("\n")
disk = d[0]
print(disk)

files = []

tmpCurr = 0

for i in range(len(disk)):
  if i % 2 == 0:
    for j in range(int(disk[i])):
      files.append(tmpCurr)
    tmpCurr += 1
  else:
    for j in range(int(disk[i])):
      files.append(-1)
lastSeen = len(disk)*2
print(files)
for i in range(len(files)):
  tmp = 0
  freeSpotSize = 0
  fileSize = 0
  sizeFinder = len(files) - 1 - i
  curr = files[len(files) - 1 - i]
  if curr == -1 or curr >= lastSeen:
    continue
  lastSeen = curr
  while files[sizeFinder] == curr:
    if sizeFinder - 1 >= 0:
      sizeFinder -= 1
      fileSize += 1
    else:
      break
  if sizeFinder == 0:
    break

  sizeFinder += 1
  
  while 1: # look for free space
    if files[tmp] == -1:
      freeSpotSize += 1
      if freeSpotSize >= fileSize:
        tmp -= (fileSize - 1)
        break
    else:
      freeSpotSize = 0
    tmp += 1
    if tmp >= len(files):
      break
  if tmp + fileSize >= (len(files)-i):
    continue
  else:
    # print("moving: ", curr)
    for l in range(fileSize):
      files[tmp + l] = curr
      files[sizeFinder + l] = -1

total = 0
# files = files[1:]
print(files)
for i in range(len(files)):
  if files[i] == -1:
    continue
  total += i * int(files[i])

print(total)