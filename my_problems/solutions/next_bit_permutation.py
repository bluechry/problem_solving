# Problem
#   Find the next permutation of a given integer's bit pattern.


# Solution #1
def next_bit_permutation1(n: int, bit_size: int) -> int:
    bin_str = bin(n)[2:].zfill(bit_size)
    lst = list(bin_str)

    for i in range(bit_size - 2, -1, -1):
        if lst[i] < lst[i + 1]:
            break
    else:
        return int(''.join(lst[::-1]), 2)

    for j in range(bit_size - 1, -1, -1):
        if lst[j] > lst[i]:
            break

    lst[i], lst[j] = lst[j], lst[i]

    lst[i+1:] = lst[i+1:][::-1]

    return int(''.join(lst), 2)


# Solution #2
def next_bit_permutation2(n: int, bit_size: int) -> int:
    num_set_bits = 0
    for i in range(bit_size - 1):
        if (n >> i) & 1:
            num_set_bits += 1

        if (n >> (i + 1)) & 1 < (n >> i) & 1:
            n |= 1 << (i + 1)
            n &= -1 << (i + 1)
            n |= (1 << (num_set_bits - 1)) - 1

            return n

    else:
        if (n >> (i + 1)) & 1:
            num_set_bits += 1

        return (1 << num_set_bits) - 1


# Solution #3
def next_bit_permutation3(n: int, bit_size: int) -> int:
    # r is the righmost set bit
    right = n & -n
    if not right:
        return n

    # high is the higher bits
    high = (n + right) & ((1 << bit_size) - 1)
    if not high:
        return n // right

    # low is the lower bits
    low = ((n ^ high) // right) >> 2

    return high | low


# Test Code
def print_bin_string(n: int, bit_size: int) -> None:
    s = bin(n)[2:].zfill(bit_size)
    print(s)


def list_all_permutation(n: int, bit_size: int, func: callable) -> int:

    orig = n
    print_bin_string(orig, bit_size)

    while True:
        p = func(n, bit_size)
        if p == orig:
            break
        else:
            print_bin_string(p, bit_size)
            n = p


if __name__ == '__main__':
    test_cases = ["0000", "0001", "0011", "0111", "1111"]
    test_funcs = [
        next_bit_permutation1,
        next_bit_permutation2,
        next_bit_permutation3
    ]

    for func in test_funcs:
        print(f"Test Func: {func.__name__}")

        for data in test_cases:
            print(f"Test Case: {data}")

            list_all_permutation(int(data, 2), 4, func)

            print()
