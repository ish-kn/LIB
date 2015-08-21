# def pow(x, n, M):
#     res = 1
#     if n > 0:
#         res = pow(x, n / 2, M)
#         if n % 2 == 0:
#             res = (res * res) % M
#         else:
#             res = (((res * res) % M) * x) % M
#     return res

M = 10**9 + 7


def power(x, n):  # pow(x, n) % M
    if n == 0:
        return 1
    res = power((x * x) % M, n / 2)
    if n % 2:
        res = (res * x) % M
    return res


def main():
    m, n = map(int, raw_input().split())
    print power(m, n)

if __name__ == '__main__':
    main()
