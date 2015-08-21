MMAX = 20
NMAX = 50000
INF = float('inf')

n = m = 0
C = [0] * (MMAX + 1)


def solve():
    T = [0] + [INF] * (NMAX)

    for i in xrange(0, m + 1):
        for j in xrange(C[i], n + 1):
            T[j] = min(T[j], T[j - C[i]] + 1)

    return T[n]


def main():
    global n, m
    n, m = map(int, raw_input().split())
    t = map(int, raw_input().split())
    for i in xrange(m):
        C[i] = t[i]

    print solve()

if __name__ == '__main__':
    main()
