# Problem
#
# Write a program to count the number of set bits in a non-negative integer.


# Approach 1
#
# T(n) = O(log n), n is the given integer
# S(n) = O(1)
def count_set_bits1(n: int) -> int:
    num_bits = 0
    while n:
        num_bits += n & 1
        n >>= 1
    return num_bits


# Approach 2
#
# T(n) = O(k), k is the number of set bits in the given integer
# S(n) = O(1)
def count_set_bits2(n: int) -> int:
    num_bits = 0
    while n:
        num_bits += 1
        n &= n - 1
    return num_bits


# Approach 3
#
# T(n) = O(log n), n is the given integer
# S(n) = O(log n)
def count_set_bits3(n: int) -> int:
    return bin(n).count('1')


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
    output.append(num_bits)

if output != answer_set:
    print("Wrong answer!")
else:
    print("All test cases passed!")
