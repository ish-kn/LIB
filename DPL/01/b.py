NMAX = 105
WMAX = 10005


class Item:

    def __init__(self, v, w):
        self.v = v
        self.w = w

N = W = 0
items = [None] * (NMAX + 1)
C = [[0 for j in xrange(WMAX + 1)] for i in xrange(NMAX + 1)]


def solve():
    for w in xrange(W + 1):
        C[0][w] = 0
    for i in xrange(1, N + 1):
        C[i][0] = 0

    for i in xrange(1, N + 1):
        for w in xrange(1, W + 1):
            C[i][w] = C[i - 1][w]
            if items[i].w > w:
                continue
            C[i][w] = max(C[i][w],
                          C[i - 1][w - items[i].w] + items[i].v)

    return C[N][W]


def main():
    global N, W
    N, W = map(int, raw_input().split())

    for i in xrange(1, N + 1):
        v, w = map(int, raw_input().split())
        items[i] = Item(v, w)

    print solve()

if __name__ == '__main__':
    main()
