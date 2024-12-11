file = open("./input.txt")
stones = file.read().split("\n")

stones = stones[0].split(' ')

# print(stones)

cache = {}

def count_stones(stone, blinks):
  # print(blinks, " : : ", stone)
  if blinks <= 0:
    return 1
  total = 0
  if stone == '0':
    tmpStr = '1:' + str(blinks-1)
    if tmpStr in cache:
      total += cache[tmpStr]
    else:
      cache[tmpStr] = count_stones('1', blinks-1)
      total += cache[tmpStr]
  elif len(stone) % 2 == 0:
    tmpStr1 = str(int(stone[:int(len(stone)/2)])) + ":" + str(blinks-1)
    tmpStr2 = str(int(stone[int(len(stone)/2):])) + ":" + str(blinks-1)
    if tmpStr1 in cache:
      total += cache[tmpStr1]
    else:
      cache[tmpStr1] = count_stones(str(int(stone[:int(len(stone)/2)])), (blinks-1))
      total += cache[tmpStr1]
    if tmpStr2 in cache:
      total += cache[tmpStr2]
    else:
       cache[tmpStr2] = count_stones(str(int(stone[int(len(stone)/2):])), (blinks-1))
       total += cache[tmpStr2]
  elif len(stone) % 2 != 0:
    tmpStr = str(int(stone) * 2024) + ":" + str(blinks-1)
    if tmpStr in cache:
      total += cache[tmpStr]
    else:
      cache[tmpStr] = count_stones(str(int(stone) * 2024), blinks-1)
      total += cache[tmpStr]
  else:
    print("something bad")
  return total

total = 0
for i in range(len(stones)):
  total += count_stones(stones[i], 25)
print("Part1: ", total)
total = 0
for i in range(len(stones)):
  total += count_stones(stones[i], 75)
print("Part2: ", total)

