def prev_permutation(s: str) -> str:
    pass


# Test Code
def list_all_permutation(s: str):
    s_orig = s
    print(s)

    while True:
        prev_s = prev_permutation(s)
        if prev_s == s_orig:
            break

        print(prev_s)
        s = prev_s


if __name__ == '__main__':
    test_cases = ["0", "1", "12", "21", "123", "321"]
    for s in test_cases:
        print(f"Test Case: {s}")

        list_all_permutation(s)

        print()
