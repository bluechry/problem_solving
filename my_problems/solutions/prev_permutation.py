def prev_permutation(s: str) -> str:
    if not s:
        raise ValueError("Invalid string.")

    lst = list(s)
    n = len(lst)

    i = n - 2
    while i >= 0 and lst[i] < lst[i+1]:
        i -= 1

    if i == -1:
        return ''.join(lst[::-1])

    j = n - 1
    while lst[i] < lst[j]:
        j -= 1

    lst[i], lst[j] = lst[j], lst[i]

    lst[i+1:] = lst[i+1:][::-1]

    return ''.join(lst)


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
