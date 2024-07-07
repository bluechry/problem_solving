# Problem
#
# Write a program to count the number of set bits in a non-negative integer.


# Solution 2
#
# T(n) = O(k), k is the number of set bits in the given integer
# S(n) = O(1)
def count_set_bits2(n: int) -> int:
    num_bits = 0
    while n:
        num_bits += 1
        n &= n - 1
    return num_bits


# Test Cases
#
# - input: 0, answer: 0
# - input: 1, answer: 1
# - input: 2, answer: 1
# - input: 3, answer: 2
# - input: 7, answer: 3
# - input: 8, answer: 1

input_set = [0, 1, 2, 3, 7, 8]
answer_set = [0, 1, 1, 2, 3, 1]
output_set = []

for n in input_set:
    num_bits = count_set_bits2(n)
    output_set.append(num_bits)

if output_set != answer_set:
    print("Wrong answer!")
else:
    print("All test cases passed!")
