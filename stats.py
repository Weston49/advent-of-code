import urllib.request, json, os
import matplotlib.pyplot as plt
import matplotlib as mpl
from datetime import datetime, timedelta

# url = "https://adventofcode.com/2024/leaderboard/private/view/2660382.json"
# aoc_session = os.getenv('aoc_session')
# headers = {'Cookie': f'session={aoc_session}'}
# request = urllib.request.Request(url, headers=headers)
# response = urllib.request.urlopen(request)
# data = json.loads(response.read())
with open('example.json', 'r') as file:
  data = json.load(file)
print(data)

# Enable dark mode
mpl.style.use('dark_background')

# Define custom colors for the first 3 members
custom_colors = ['#ff0000', '#00ff00', '#0000ff']

# Extract data for graphing
members = data['members']
member_names = []

plt.figure(figsize=(10, 8))  

bar_width = 1
num_members = len(members)
max_y_value = 0  # Track the maximum y value for setting the y-axis limit

# Find the maximum days any user has completed
max_days = max(int(day) for member_info in members.values() for day in member_info['completion_day_level'].keys())

for idx, (member_id, member_info) in enumerate(members.items()):
    member_name = member_info['name']
    completion_times_part1 = []
    completion_times_part2 = []
    star_indices = []

    for day in range(1, max_days + 1):
        day_str = str(day)
        day_start = datetime(2024, 12, day)
        part1_time = -3  # Default to -3 if no data for both parts
        part2_time = -3  # Default to -3 if no data for both parts

        if day_str in member_info['completion_day_level']:
            stars = member_info['completion_day_level'][day_str]
            if '1' in stars:
                get_star_ts = stars['1']['get_star_ts']
                time_after_start = datetime.fromtimestamp(get_star_ts) - day_start
                part1_time = time_after_start.total_seconds() / 3600  # Convert to hours
                if part1_time > 24:
                    part1_time = -1  # Set to -1 if above 24 hours
                max_y_value = max(max_y_value, part1_time)
            else:
                part1_time = -2  # Set to -2 if no data for part 1

            if '2' in stars:
                get_star_ts = stars['2']['get_star_ts']
                time_after_start = datetime.fromtimestamp(get_star_ts) - day_start
                part2_time = time_after_start.total_seconds() / 3600  # Convert to hours
                if part2_time > 24:
                    part2_time = -1  # Set to -1 if above 24 hours
                part2_time -= part1_time  # Stack part 2 on top of part 1
                max_y_value = max(max_y_value, part2_time + part1_time)
            else:
                part2_time = -2  # Set to -2 if no data for part 2

        completion_times_part1.append(part1_time)
        completion_times_part2.append(part2_time)
        star_indices.append(day + (idx * bar_width / num_members))  # Offset bars for each member

    color = custom_colors[idx] if idx < 3 else plt.cm.tab10(idx % 10)  # Use custom colors for first 3 members, colormap for others
    plt.bar(star_indices, completion_times_part1, width=bar_width / num_members, label=member_name, color=color, alpha=0.6)
    plt.bar(star_indices, completion_times_part2, width=bar_width / num_members, bottom=completion_times_part1, color=color)

# Plotting the data
plt.ylabel('Hours After Start of Day')
plt.xlabel('Day')
plt.title('Advent of Code Completion Times')
plt.legend(loc='upper right')  # Adjust legend position
plt.ylim(-3, max_y_value)  # Set y-axis limit to the actual max value
plt.yticks(range(-3, int(max_y_value) + 1), labels=['Not Started' if i == -3 else 'Only Part 1' if i == -2 else '24+' if i == -1 else str(i) for i in range(-3, int(max_y_value) + 1)])  # Set y-ticks and labels
current_day = datetime.now().day
plt.xticks(ticks=[x - (1/(len(members)*2)) for x in range(1, current_day + 2)], labels=range(1, current_day + 2))

# Add vertical lines at each x value tick mark
for x in range(1, current_day + 2):
    plt.axvline(x=x - (1/(len(members)*2)), color='gray', linestyle='--', linewidth=0.5)

# Hide the x-axis, y-axis, right, and top lines
ax = plt.gca()
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

# Draw a thick white line at y = 0
plt.axhline(y=0, color='white', linewidth=2)

plt.tight_layout()
plt.show()


