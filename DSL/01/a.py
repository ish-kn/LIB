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


def main():
    n, q = map(int, raw_input().split())
    ds = DisjointSet(n)

    for i in xrange(q):
        t, a, b = map(int, raw_input().split())
        if t == 0:
            ds.unite(a, b)
        else:
            print 1 if ds.same(a, b) else 0

if __name__ == '__main__':
    main()
