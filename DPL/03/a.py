MAX = 1400

H = W = 0
dp = [[0 for j in xrange(MAX)] for i in xrange(MAX)]
G = [[0 for j in xrange(MAX)] for i in xrange(MAX)]


def solve():
    maxWidth = 0
    for i in xrange(H):
        for j in xrange(W):
            dp[i][j] = (G[i][j] + 1) % 2
            maxWidth |= dp[i][j]

    for i in xrange(1, H):
        for j in xrange(1, W):
            if G[i][j]:
                dp[i][j] = 0
            else:
                dp[i][j] = min(dp[i - 1][j - 1],
                               min(dp[i - 1][j], dp[i][j - 1])) + 1
                maxWidth = max(maxWidth, dp[i][j])

    return maxWidth * maxWidth


def main():
    global H, W
    H, W = map(int, raw_input().split())
    for i in xrange(H):
        t = map(int, raw_input().split())
        for j in xrange(W):
            G[i][j] = t[j]

    print solve()

if __name__ == '__main__':
    main()
