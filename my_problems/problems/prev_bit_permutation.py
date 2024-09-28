from typing import Callable


# A given integer is assumed to be 4-bit value.
NUM_BITS = 4
BIT_FORMAT = '04b'


def get_bit_pattern(x: int) -> str:
    return format(x, BIT_FORMAT)


# Solution 1: Flip the right-most '01' bit pattern
def prev_bit_permutation(x: int) -> int:
    for i in range(NUM_BITS - 1):
        if (x >> (i + 1)) & 1 == 1 and (x >> i) & 1 == 0:
            bit_mask = (1 << (i + 1)) | (1 << i)
            return x ^ bit_mask
    else:
        bit_str = get_bit_pattern(x)
        prev_str = ''.join(sorted(bit_str, reverse=True))
        return int(prev_str, 2)


# Test Code
# A given integer x should be a 4-bit value.
def list_all_permutation(x: int, func: Callable) -> None:
    num = x
    print(get_bit_pattern(num))

    while True:
        prev = func(num)
        if prev == x:
            break

        print(get_bit_pattern(prev))
        num = prev


test_cases = [0b0000, 0b0001, 0b0011, 0b0111, 0b1111]
for x in test_cases:
    print(f"Test Case: {get_bit_pattern(x)}")
    list_all_permutation(x, prev_bit_permutation)
    print()
