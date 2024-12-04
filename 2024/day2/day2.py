#Boilerplate reading the file input
def read_input(file_path):
  with open(file_path, 'r') as file:
    return file.readlines()
d = read_input('./input.txt')

d = [d[i].split() for i in range(len(d))]

def is_report_safe(row):
  return all((abs(int(row[i]) - int(row[i+1])) < 4) for i in range(len(row)-1)) and (all(int(row[i]) > int(row[i+1]) for i in range(len(row)-1)) or all(int(row[i]) < int(row[i+1]) for i in range(len(row)-1)))

print("Part 1: ", sum(1 for report in d if is_report_safe(report)))

print("Part 2: ", sum(1 for report in d if(any(is_report_safe(report[:i] + report[i+1:]) for i in range(len(report))))))