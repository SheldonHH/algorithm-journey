MAXN = 1000001
OFFSET = 30001
arr = [0] * (OFFSET + MAXN + OFFSET)

def set_op(l, r, s, e, d):
    arr[l + OFFSET] += s
    arr[l + 1 + OFFSET] += d - s
    arr[r + 1 + OFFSET] -= d + e
    arr[r + 2 + OFFSET] += e

def build(m):
    for i in range(1, m + OFFSET + 1):
        arr[i] += arr[i - 1]
    for i in range(1, m + OFFSET + 1):
        arr[i] += arr[i - 1]

while True:
    try:
        n, m = map(int, input().split())
        for _ in range(n):
            v, x = map(int, input().split())
            set_op(x - 3 * v + 1, x - 2 * v, 1, v, 1)
            set_op(x - 2 * v + 1, x, v - 1, -v, -1)
            set_op(x + 1, x + 2 * v, -v + 1, v, 1)
            set_op(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1)
        build(m)
        print(" ".join(map(str, arr[OFFSET + 1 : OFFSET + m + 1])))
    except EOFError:
        break
