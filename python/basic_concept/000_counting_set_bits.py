#!/usr/bin/env python

# Problem Definition


# Solution I



# Solution II
def count_set_bits2(x: int) -> int:
  num_bits = 0
  while x:
    num_bits += x & 1
    x >>= 1
  return num_bits


# Solution III
def count_set_bits3(x: int) -> int:
  num_bits = 0
  while x:
    num_bits += 1
    x &= x - 1
  return num_bits


# Test Cases
for i in range(0, 10):
  ans2 = count_set_bits2(i)
  ans3 = count_set_bits3(i)

  if ans2 != ans3:
    print(f'Error occurs at {i}')
