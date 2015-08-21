from sets import Set
import sys

MAX = 100000
sys.setrecursionlimit(MAX)

G = [[] for i in xrange(MAX)]
N = 0
visited = [False] * MAX
prenum, parent, lowest = [0] * MAX, [0] * MAX, [0] * MAX
timer = 1


def dfs(current, prev):
    global timer
    prenum[current] = lowest[current] = timer
    timer += 1

    visited[current] = True

    for i in xrange(len(G[current])):
        next = G[current][i]
        if not visited[next]:
            parent[next] = current

            dfs(next, current)

            lowest[current] = min(lowest[current], lowest[next])
        elif next != prev:
            lowest[current] = min(lowest[current], prenum[next])


def art_points():
    dfs(0, -1)  # 0 == root

    ap = Set()
    np = 0
    for i in xrange(1, N):
        p = parent[i]
        if p == 0:
            np += 1
        elif prenum[p] <= lowest[i]:
            ap.add(p)
    if np > 1:
        ap.add(0)
    for u in sorted(ap):
        print u


def main():
    global N
    N, m = map(int, raw_input().split())

    for i in xrange(m):
        s, t = map(int, raw_input().split())
        G[s].append(t)
        G[t].append(s)
    art_points()

if __name__ == '__main__':
    main()
