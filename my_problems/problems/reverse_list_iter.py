from typing import Callable


# Solution 1: Reverse the list using accumulator pattern
def reverse_list_1(elems: list) -> list:
    result = []

    for i in elems:
        result = [i] + result

    return result


# Solution 2: Reverse the list using list slicing
def reverse_list_2(elems: list) -> list:
    return elems[::-1]


# Solution 3: Reverse the list in-place using a two-pointer approach
def reverse_list_3(elems: list) -> list:
    i = 0
    j = len(elems) - 1

    while i < j:
        elems[i], elems[j] = elems[j], elems[i]
        i += 1
        j -= 1

    # 여기서 elems를 반환하지 않아도 elems가 가리키는 리스트는 이미 변경된
    # 상태다. 테스트 코드를 위하여 elems를 반환한다.
    return elems


# Solution 4: Reverse the list in-place using the built-in method
def reverse_list_4(elems: list) -> list:
    # elems.reverse()는 None를 반환하므로 반드시 elems를 반환해야 한다.
    elems.reverse()
    return elems


def run_test(elems: list, func: Callable) -> list:
    pass
