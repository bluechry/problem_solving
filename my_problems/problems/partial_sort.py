def partial_sort_list(lst: list, start: int, end: int) -> list:
    pass


def partial_sort_string(s: str, start: int, end: int) -> list:
    pass


def test_partial_sort_list():
    print("Testing partial_sort_list...")

    # Test case 1: Normal case
    lst1 = [10, 5, 3, 8, 6, 1, 7, 2]
    result1 = partial_sort_list(lst1, 2, 5)
    print(f"Test 1 - Input: {lst1}, Output: {result1}, "
          f"Expected: [10, 5, 1, 3, 6, 8, 7, 2]")

    # Test case 2: Entire list
    lst2 = [9, 7, 5, 3, 1]
    result2 = partial_sort_list(lst2, 0, 4)
    print(f"Test 2 - Input: {lst2}, Output: {result2}, "
          f"Expected: [1, 3, 5, 7, 9]")

    # Test case 3: Single element range
    lst3 = [3, 2, 1, 4, 5]
    result3 = partial_sort_list(lst3, 1, 1)
    print(f"Test 3 - Input: {lst3}, Output: {result3}, "
          f"Expected: [3, 2, 1, 4, 5]")

    # Test case 4: Invalid range (should raise error)
    try:
        partial_sort_list([1, 2, 3, 4], -1, 3)
    except ValueError as e:
        print(f"Test 4 - Error as expected: {e}")

    print()


def test_partial_sort_string():
    print("Testing partial_sort_string...")

    # Test case 1: Normal case
    s1 = "pythonisfun"
    result1 = partial_sort_string(s1, 2, 7)
    print(f"Test 1 - Input: {s1}, Output: {result1}, "
          f"Expected: 'pyfhinosun'")

    # Test case 2: Entire string
    s2 = "openai"
    result2 = partial_sort_string(s2, 0, 5)
    print(f"Test 2 - Input: {s2}, Output: {result2}, "
          f"Expected: 'aeinop'")

    # Test case 3: Single character range
    s3 = "abcde"
    result3 = partial_sort_string(s3, 2, 2)
    print(f"Test 3 - Input: {s3}, Output: {result3}, "
          f"Expected: 'abcde'")

    # Test case 4: Invalid range (should raise error)
    try:
        partial_sort_string("abcd", 3, 7)
    except ValueError as e:
        print(f"Test 4 - Error as expected: {e}")

    print()


if __name__ == "__main__":
    test_partial_sort_list()
    test_partial_sort_string()
