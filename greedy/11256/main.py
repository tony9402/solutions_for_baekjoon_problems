# Authored by : gd30220
# Co-authored by : -
# Link : http://boj.kr/fb3874925c8049e58f475817595d442a


t = int(input())
for _ in range(t):
    j, n = map(int, input().split())

    box = []
    for _ in range(n):
        r, c = map(int, input().split())
        box.append(r * c)

    box.sort(reverse=True)
    result = 0

    for box in boxes:
        j -= box
        result += 1
        if j <= 0:
            break

    print(result)

