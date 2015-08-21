from collections import deque

MAX = 100000
INF = float('inf')

G = [[] for i in xrange(MAX)]
out = []
V = [False] * MAX
N = 0
indeg = [0] * MAX


def bfs(s):
    q = deque()
    q.append(s)
    V[s] = True
    while len(q):
        u = q.popleft()
        out.append(u)
        for i in xrange(len(G[u])):
            v = G[u][i]
            indeg[v] -= 1
            if indeg[v] == 0 and not V[v]:
                V[v] = True
                q.append(v)


def tsort():
    for u in xrange(N):
        for i in xrange(len(G[u])):
            v = G[u][i]
            indeg[v] += 1

    for u in xrange(N):
        if indeg[u] == 0 and not V[u]:
            bfs(u)

    for u in out:
        print u


def main():
    global N
    N, M = map(int, raw_input().split())
    for i in xrange(M):
        s, t = map(int, raw_input().split())
        G[s].append(t)

    tsort()

if __name__ == '__main__':
    main()
