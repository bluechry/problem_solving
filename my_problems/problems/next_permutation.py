def next_permutation(s: str) -> str:
    pass


# Test Code
def list_all_permutation(s: str):
    s_orig = s
    print(s)

    while True:
        next_s = next_permutation(s)
        if next_s == s_orig:
            break

        print(next_s)
        s = next_s


if __name__ == '__main__':
    test_cases = ["0", "1", "12", "21", "123", "321"]
    for s in test_cases:
        print(f"Test Case: {s}")

        list_all_permutation(s)

        print()
