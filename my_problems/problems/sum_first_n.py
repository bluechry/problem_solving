# Solution: Use recursion
#   * Base case:
#     sum(0) = 0
#   * Recursive Case
#     sum_first_n(n) = sum_first_n(n-1) + n
def sum_first_n(n: int) -> int:
    pass


# Test Code
def test():
    for n in range(10):
        sum = sum_first_n(n)
        print(f'Sum 0 ~ {n}: {sum}')


if __name__ == '__main__':
    test()
