def solve(s1, s2):
    l1 = len(s1)
    l2 = len(s2)
    s1 = ' ' + s1
    s2 = ' ' + s2
    dp = [[0 for j in xrange(l2 + 1)] for i in xrange(l1 + 1)]
    for i in xrange(l1 + 1):
        dp[i][0] = i
    for i in xrange(l2 + 1):
        dp[0][i] = i

    for i in xrange(1, l1 + 1):
        for j in xrange(1, l2 + 1):
            cost = 0
            if s1[i] != s2[j]:
                cost = 1
            dp[i][j] = min(
                dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost)

    return dp[l1][l2]


def main():
    s1 = raw_input()
    s2 = raw_input()
    print solve(s1, s2)


if __name__ == '__main__':
    main()
