MAX = 1400


H = W = 0
buf = [[0 for j in xrange(MAX)] for i in xrange(MAX)]
T = [[0 for j in xrange(MAX)] for i in xrange(MAX)]


class Rectangle:

    def __init__(self, h, p):
        self.height = h
        self.pos = p


def getLargestRectangle(size, buf):
    S = []
    maxv = 0
    buf[size] = 0

    for i in xrange(size + 1):
        rect = Rectangle(buf[i], i)
        if len(S) == 0:
            S.append(rect)
        else:
            if S[len(S) - 1].height < rect.height:
                S.append(rect)
            elif S[len(S) - 1].height > rect.height:
                target = i
                while len(S) and S[len(S) - 1].height >= rect.height:
                    pre = S.pop()
                    area = pre.height * (i - pre.pos)
                    maxv = max(maxv, area)
                    target = pre.pos
                rect.pos = target
                S.append(rect)

    return maxv


def solve():
    for j in xrange(W):
        for i in xrange(H):
            if buf[i][j]:
                T[i][j] = 0
            else:
                T[i][j] = (T[i - 1][j] + 1) if i > 0 else 1

    maxv = 0
    for i in xrange(H):
        maxv = max(maxv, getLargestRectangle(W, T[i]))

    return maxv


def main():
    global H, W
    H, W = map(int, raw_input().split())
    for i in xrange(H):
        t = map(int, raw_input().split())
        for j in xrange(W):
            buf[i][j] = t[j]

    print solve()

if __name__ == '__main__':
    main()
