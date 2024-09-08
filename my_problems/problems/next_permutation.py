def next_permutation(s: str):
    if not s:
        raise ValueError("Invalid string.")

    lst = list(s)

    i = len(lst) - 2
    while i >= 0 and lst[i] > lst[i+1]:
        i -= 1

    if i == -1:
        return ''.join(lst[::-1])

    j = len(lst) - 1
    while lst[i] > lst[j]:
        j -= 1

    lst[i], lst[j] = lst[j], lst[i]

    lst[i+1:] = lst[i+1:][::-1]

    return ''.join(lst)


def list_all_permutation(s: str):
    next_s = s
    print(next_s)

    while True:
        next_s = next_permutation(next_s)
        if next_s ==s:
            break
        print(next_s)


if __name__ == '__main__':
    list_all_permutation("1234")
    list_all_permutation("")
