import os
from datetime import datetime

count = 0

for item in os.listdir():
    if os.path.isdir(item) and item[:4].isdigit():
        count += 1

content = f"""# LeetCode Solutions

## Statistics

- Total Problems Solved: {count}
- Last Updated: {datetime.now().strftime("%d %B %Y")}
"""

with open("README.md", "w") as f:
    f.write(content)
