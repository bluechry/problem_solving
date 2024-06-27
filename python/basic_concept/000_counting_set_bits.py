#!/usr/bin/env python

# Problem Definition

# Solution I
def count_set_bits1(x: int) -> int:
  num_bits = 0
  while x:
    num_bits += x & 1
    x >>= 1
  return num_bits


# Solution II
def count_set_bits2(x: int) -> int:
  num_bits = 0
  while x:
    num_bits += 1
    x &= x - 1
  return num_bits


# Test Cases
for i in range(0, 10):
  ans1 = count_set_bits1(i)
  ans2 = count_set_bits2(i)

  if ans1 != ans2:
    print(f'Error occurs at {i}')
