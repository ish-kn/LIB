import sys
p = sys.stdout.write

MAX = 100
INF = float('inf')

n = 0
d = [[0 for j in xrange(MAX)] for i in xrange(MAX)]


def floyd():
    for k in xrange(n):
        for i in xrange(n):
            if d[i][k] == INF:
                continue
            for j in xrange(n):
                if d[k][j] == INF:
                    continue
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])


def main():
    global n
    n, e = map(int, raw_input().split())
    for i in xrange(n):
        for j in xrange(n):
            d[i][j] = 0 if i == j else INF
    for i in xrange(e):
        u, v, c = map(int, raw_input().split())
        d[u][v] = c

    floyd()

    negative = False
    for i in xrange(n):
        if d[i][i] < 0:
            negative = True

    if negative:
        print 'NEGATIVE CYCLE'
    else:
        for i in xrange(n):
            for j in xrange(n):
                if j:
                    p(' ')
                if d[i][j] == INF:
                    p('INF')
                else:
                    p(str(d[i][j]))
            print ''


if __name__ == '__main__':
    main()
