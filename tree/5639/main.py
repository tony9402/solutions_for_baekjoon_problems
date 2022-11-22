# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/e147b2c00af141aa9ec90fd7fa56cf9f
import sys

sys.setrecursionlimit(10 ** 6)
read = lambda: sys.stdin.readline().rstrip()
lst = list()
while True:
    try:
        lst.append(int(read()))
    except:
        break

def postorder(start, end):      # postorder by recursion
    if start > end:
        return
    mid = end + 1
    for i in range(start + 1, end + 1):
        if lst[start] < lst[i]:
            mid = i
            break

    postorder(start + 1, mid - 1)
    postorder(mid, end)
    print(lst[start])

postorder(0, len(lst) - 1)
