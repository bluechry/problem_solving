from typing import Callable


# A given integer is assumed to be 4-bit value.
NUM_BITS = 4
BIT_FORMAT = '04b'


def get_bit_pattern(x: int) -> str:
    return format(x, BIT_FORMAT)


# Solution 1: Flip the right-most '01' bit pattern
def prev_bit_permutation(x: int) -> int:
    pass


# Test Code
# A given integer x should be a 4-bit value.
def list_all_permutation(x: int, func: Callable) -> None:
    n = x
    print(get_bit_pattern(n))

    while True:
        prev_n = func(n)
        if prev_n == x:
            break

        print(get_bit_pattern(prev_n))
        n = prev_n


if __name__ == '__main__':
    test_cases = [0b0000, 0b0001, 0b0011, 0b0111, 0b1111]
    for x in test_cases:
        print(f"Test Case: {get_bit_pattern(x)}")

        list_all_permutation(x, prev_bit_permutation)

        print()
