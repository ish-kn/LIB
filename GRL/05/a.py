from collections import deque

MAX = 100000
INF = float('inf')


class Edge:

    def __init__(self, t, w):
        self.t = t
        self.w = w

G = [[] for i in xrange(MAX)]
n = 0
d = []


def bfs(s):
    global d
    d = [INF] * n
    q = deque()
    q.append(s)
    d[s] = 0
    while len(q):
        u = q.popleft()
        for i in xrange(len(G[u])):
            e = G[u][i]
            if d[e.t] == INF:
                d[e.t] = d[u] + e.w
                q.append(e.t)


def solve():
    bfs(0)
    maxv = 0
    tgt = 0
    for i in xrange(n):
        if d[i] == INF:
            continue
        if maxv < d[i]:
            maxv = d[i]
            tgt = i

    bfs(tgt)
    maxv = 0
    for i in xrange(n):
        if d[i] == INF:
            continue
        maxv = max(maxv, d[i])

    print maxv


def main():
    global n
    n = input()
    for i in xrange(n - 1):
        s, t, w = map(int, raw_input().split())
        G[s].append(Edge(t, w))
        G[t].append(Edge(s, w))
    solve()

if __name__ == '__main__':
    main()
