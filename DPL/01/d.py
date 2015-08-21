from bisect import *

MAX = 100000

n = 0
A = [0] * (MAX + 1)
L = [0] * MAX


def lis():
    L[0] = A[0]
    length = 1

    for i in xrange(1, n):
        if L[length - 1] < A[i]:
            L[length] = A[i]
            length += 1
        else:
            idx = bisect_left(L, A[i], 0, length)
            L[idx] = A[i]

    return length


def main():
    global n
    n = input()
    for i in xrange(n):
        A[i] = input()

    print lis()

if __name__ == '__main__':
    main()
