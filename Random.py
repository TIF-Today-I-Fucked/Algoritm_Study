import os
import random

os.chdir("./Algorithms/DFS_BFS")
lst = os.listdir()
new_list1 = [string.replace("[Baekjoon]_", "") for string in lst]

os.chdir("../BackTracking")
lst = os.listdir()
new_list2 = [string.replace("[Baekjoon]_", "") for string in lst]

new_list = new_list1 + new_list2
random_items = random.sample(new_list, k=2)

print(" 🔥 오늘의 문제는 ?!")
print("	첫 번째, 두 번째 문제 ->", random_items ," 입니다!")

