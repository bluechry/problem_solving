# Right propagate the rightmost set bit in x
def propagate_rightmost_bit(x: int) -> int:
    pass


# Compute x mod a power of two
def mod_power_of_two(x: int, n: int) -> int:
    pass


# Test if x is a power of two
def test_power_of_two(x: int) -> int:
    pass


if __name__ == '__main__':

    # Test 1
    x = 0b10100
    result = propagate_rightmost_bit(x)

    if result != 0b10111:
        print("Test 1 failed.")

    # Test 2
    x = 77
    mod = mod_power_of_two(x, n=6)

    if mod != 13:
        print("Test 2 failed.")

    # Test 3
    x = 0b0010000
    if not test_power_of_two(x):
        print("Test 3 failed.")
        exit(1)

    x = 0b0011000
    if test_power_of_two(x):
        print("Test 3 failed.")
        exit(1)

    x = 0b0
    if test_power_of_two(x):
        print("Test 3 failed.")
        exit(1)

    print("All tests passed.")
