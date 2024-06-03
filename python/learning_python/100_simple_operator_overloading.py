from __future__ import annotations

class Node:
    def __init__(self, key: str, value: int) -> None:
        self.key = key
        self.value = value

    def __add__(self, other: Node) -> Node:
        new_key = self.key + other.key
        new_value = self.value + other.value
        return Node(new_key, new_value)

    def __repr__(self):
        return f'Node({self.key}: {self.value})'


def test() -> None:
    node_a = Node(key = 'A', value = 100)
    node_b = Node(key = 'B', value = 200)
    node_c = node_a + node_b

    print(node_a)
    print(node_b)
    print(f'node_a + node_b = {node_c}')


if __name__ == '__main__':
    test()
