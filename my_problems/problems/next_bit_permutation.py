# Problem
#   Find the next permutation of a given integer's bit pattern.


# Solution #1
def next_bit_permutation1(n: int, bit_size: int) -> int:
    pass


# Solution #2
def next_bit_permutation2(n: int, bit_size: int) -> int:
    pass


# Solution #3
def next_bit_permutation3(n: int, bit_size: int) -> int:
    pass


# Test Code
def print_bin_string(n: int, bit_size: int) -> None:
    s = bin(n)[2:].zfill(bit_size)
    print(s)


def list_all_permutation(n: int, bit_size: int) -> int:

    orig = n
    print_bin_string(orig, bit_size)

    while True:
        p = next_bit_permutation1(n, bit_size)
        if p == orig:
            break
        else:
            print_bin_string(p, bit_size)
            n = p


if __name__ == '__main__':
    test_cases = ["0000", "0001", "0011", "0111", "1111"]

    for s in test_cases:
        print(f"Test Case: {s}")

        list_all_permutation(int(s, 2), 4)

        print()
