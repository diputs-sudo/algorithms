"""
Tournament Sort Algorithm

Tournament Sort is a comparison based sorting algorithm inspired by
a knockout tournament structure.

How it works:
- Elements are placed in the leaves of a binary tree.
- Each internal node stores the minimum of its two children.
- The root always contains the smallest element in the structure.
- The minimum element is extracted and replaced with infinity.
- The tree is updated from the leaf to the root.
- The process repeats until all elements are extracted.

This approach simulates repeatedly selecting the minimum efficiently.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to the tournament tree structure.

Stability:
- Not stable in general.
"""

import math


def _build_tree(a):
    n = len(a)
    size = 1 << (n - 1).bit_length()
    offset = size

    tree = [float("inf")] * (2 * size)

    for i in range(n):
        tree[offset + i] = a[i]

    for i in range(offset - 1, 0, -1):
        tree[i] = min(tree[2 * i], tree[2 * i + 1])

    return tree, offset, size


def _update_tree(tree, index):
    i = index // 2
    while i >= 1:
        tree[i] = min(tree[2 * i], tree[2 * i + 1])
        i //= 2


def tournament_sort_verbose(arr):
    a = arr[:]
    n = len(a)

    print("Start:", a)

    tree, offset, size = _build_tree(a)

    print("\nInitial tournament tree as array:")
    print(tree)

    result = []
    step = 1

    for _ in range(n):
        winner = tree[1]
        print(f"\nStep {step}: current winner is {winner}")
        result.append(winner)

        i = 1
        while i < offset:
            left = 2 * i
            right = 2 * i + 1
            if tree[left] == winner:
                i = left
            else:
                i = right

        print(f"  Winner found at leaf index {i}, replacing with infinity")
        tree[i] = float("inf")

        _update_tree(tree, i)

        print("  Tree after update:")
        print(" ", tree)
        print("  Result so far:", result)

        step += 1

    print("\nSorted:", result)
    return result


def tournament_sort(arr):
    a = arr[:]
    n = len(a)

    tree, offset, size = _build_tree(a)

    result = []

    for _ in range(n):
        winner = tree[1]
        result.append(winner)

        i = 1
        while i < offset:
            left = 2 * i
            right = 2 * i + 1
            if tree[left] == winner:
                i = left
            else:
                i = right

        tree[i] = float("inf")
        _update_tree(tree, i)

    return result