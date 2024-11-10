# Problem


# Solution #1
def next_bit_permutation1(n: int, bit_size: int) -> int:
    pass


# Solution #2
def next_bit_permutation2(n: int, bit_size: int) -> int:
    num_set_bits = 0
    for i in range(bit_size - 1):
        if n & (1 << i):
            num_set_bits += 1

        if n & (1 << (i + 1)) < n & (1 << i):
            n |= 1 << (i + 1)
            n &= -1 << (i + 1)
            n |= (1 << (num_set_bits - 1)) - 1

            return n
    else:
        if n & (1 << (i + 1)):
            num_set_bits += 1

        return (1 << num_set_bits) - 1


# Test Code
def list_all_permutation(n: int, bit_size: int) -> int:

    def print_bin_string(n: int, bit_size: int) -> None:
        s = bin(n)[2:].zfill(bit_size)
        print(s)

    orig = n
    print_bin_string(orig, bit_size)

    while True:
        p = next_bit_permutation2(n, bit_size)
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
