# https://usaco.org/index.php?page=viewproblem2&cpid=1277

n = int(input())
for _ in range(n):
    text = input()
    length = len(text)
    if length < 3:
        print(-1)
        continue
    if length == 3 and text[1] == "M":
        print(-1)
        continue
    moves = 0
    if "MOO" in text:
        print(length - 3)
        continue
    elif "OOO" in text:
        print(length - 2)
    elif "MOM" in text:
        print(length - 2)
        continue
    elif "OOM" in text:
        print(length - 1)
        continue
    else:
        print(-1)