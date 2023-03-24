import os
import random

os.chdir("./Algorithms/DynamicProgramming")
lst = os.listdir()
new_list = [string.replace("[Baekjoon]_", "") for string in lst]
random_items = random.sample(new_list, k=2)

print(" 🔥 오늘의 문제는 ?!")
print("	첫 번째, 두 번째 문제 ->", random_items ," 입니다!")
