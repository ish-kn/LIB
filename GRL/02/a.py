import operator

MAX = 10000
INF = float('inf')


class DisjointSet:

    def __init__(self, size):
        self.rank = [0] * size
        self.p = [0] * size
        for i in xrange(size):
            self.makeSet(i)

    def makeSet(self, x):
        self.p[x] = x
        self.rank[x] = 0

    def same(self, x, y):
        return self.findSet(x) == self.findSet(y)

    def unite(self, x, y):
        self.link(self.findSet(x), self.findSet(y))

    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            self.p[y] = x
        else:
            self.p[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1

    def findSet(self, x):
        if x != self.p[x]:
            self.p[x] = self.findSet(self.p[x])
        return self.p[x]


class Edge:

    def __init__(self, s, t, c):
        self.source = s
        self.target = t
        self.cost = c


def kruskal(N, edges):
    totalCost = 0
    edges.sort(key=operator.attrgetter('cost'))

    dset = DisjointSet(N + 1)
    for i in xrange(N):
        dset.makeSet(i)

    for e in edges:
        if not dset.same(e.source, e.target):
            totalCost += e.cost
            dset.unite(e.source, e.target)
    return totalCost


def main():
    N, M = map(int, raw_input().split())

    edges = [None] * M
    for i in xrange(M):
        s, t, c = map(int, raw_input().split())
        edges[i] = Edge(s, t, c)

    print kruskal(N, edges)

if __name__ == '__main__':
    main()
