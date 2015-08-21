# -*- coding: utf-8 -*-
from math import *

EPS = 1e-10


def equals(a, b):
    return fabs(a - b) < EPS


class Point:

    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)

    def __add__(self, p):
        return Point(self.x + p.x, self.y + p.y)

    def __sub__(self, p):
        return Point(self.x - p.x, self.y - p.y)

    def __mul__(self, a):
        return Point(a * self.x, a * self.y)

    def __div__(self, a):
        return Point(self.x / a, self.y / a)

    def norm(self):
        return self.x**2 + self.y**2

    def abs(self):
        return sqrt(self.norm())

    def __lt__(self, p):
        return self.x < p.x if self.x != p.x else self.y < p.y

    def __eq__(self, p):
        return equals(self.x, p.x) and equals(self.y, p.y)
Vector = Point


def dot(a, b):  # 内積
    return a.x * b.x + a.y * b.y


def cross(a, b):  # 外積
    return a.x * b.y - a.y * b.x


def contains(g, p):  # 点の内包
    # IN 2 ON 1 OUT 0
    n = len(g)
    x = False
    for i in xrange(n):
        a = g[i] - p
        b = g[(i + 1) % n] - p
        if abs(cross(a, b)) < EPS and dot(a, b) < EPS:
            return 1
        if a.y > b.y:
            a, b = b, a
        if a.y < EPS < b.y and cross(a, b) > EPS:
            x = not x
    return 2 if x else 0


def main():
    n = input()
    g = [None] * n
    for i in xrange(n):
        x, y = map(int, raw_input().split())
        g[i] = Point(x, y)

    q = input()
    for i in xrange(q):
        x, y = map(int, raw_input().split())
        p = Point(x, y)
        print contains(g, p)

if __name__ == '__main__':
    main()
