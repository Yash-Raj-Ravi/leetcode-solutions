import os
from datetime import datetime

count = 0

for item in os.listdir("."):
    if os.path.isdir(item):
        if item[0].isdigit():
            count += 1

readme = f"""# LeetCode Solutions

## Statistics

- Total Problems Solved: {count}
- Last Updated: {datetime.now().strftime("%d %B %Y")}

"""

with open("README.md", "w") as f:
    f.write(readme)
