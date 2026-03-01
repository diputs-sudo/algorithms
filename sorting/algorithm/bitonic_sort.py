"""
Bitonic Sort Algorithm

Bitonic Sort is a comparison based sorting algorithm commonly used in
parallel computing environments.

How it works:
- It recursively builds bitonic sequences.
- A bitonic sequence first increases and then decreases.
- These sequences are merged using compare and swap operations.
- Repeated merging produces a fully sorted sequence.

Classic Bitonic Sort assumes the input size is a power of two.

This educational implementation:
- Automatically pads the list to the next power of two using infinity.
- Removes the padding after sorting.
- Supports a verbose mode for visualization.

Time Complexity:
- Worst Case: O(n log^2 n)
- Average Case: O(n log^2 n)
- Best Case: O(n log^2 n)

Space Complexity:
- O(n) due to padding and recursive structure.

Stability:
- Not stable.
"""

import math


def _is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0


def _next_power_of_two(n):
    return 1 << (n - 1).bit_length()


def _compare_and_swap(a, i, j, ascending, verbose=False, step=None):
    if verbose:
        direction = "ascending" if ascending else "descending"
        print(f"Step {step}: compare {a[i]} and {a[j]} ({direction})")

    if (ascending and a[i] > a[j]) or (not ascending and a[i] < a[j]):
        if verbose:
            print(f"  swap {a[i]} and {a[j]}")
        a[i], a[j] = a[j], a[i]
        if verbose:
            print("  result:", a)
    else:
        if verbose:
            print("  no swap")


def _bitonic_merge(a, low, cnt, ascending, verbose=False, step=1):
    if cnt > 1:
        k = cnt // 2
        for i in range(low, low + k):
            _compare_and_swap(a, i, i + k, ascending, verbose, step)
            step += 1

        step = _bitonic_merge(a, low, k, ascending, verbose, step)
        step = _bitonic_merge(a, low + k, k, ascending, verbose, step)

    return step


def _bitonic_sort(a, low, cnt, ascending, verbose=False, step=1):
    if cnt > 1:
        k = cnt // 2

        if verbose:
            direction = "ascending" if ascending else "descending"
            print(f"\nBuild bitonic sequence from index {low} count {cnt} ({direction})")

        step = _bitonic_sort(a, low, k, True, verbose, step)
        step = _bitonic_sort(a, low + k, k, False, verbose, step)
        step = _bitonic_merge(a, low, cnt, ascending, verbose, step)

    return step


def bitonic_sort_verbose(arr):
    a = arr[:]
    n = len(a)

    print("Start:", a)

    target = _next_power_of_two(n)
    if target != n:
        print("Note: Bitonic sort works best when length is a power of two.")
        print(f"Padding array from length {n} to {target} using infinity.")
        pad_value = float("inf")
        a.extend([pad_value] * (target - n))
        print("Working array:", a)

    _bitonic_sort(a, 0, len(a), True, verbose=True, step=1)

    a = [x for x in a if x != float("inf")]

    print("\nSorted:", a)
    return a


def bitonic_sort(arr):
    a = arr[:]
    n = len(a)

    target = _next_power_of_two(n)
    if target != n:
        pad_value = float("inf")
        a.extend([pad_value] * (target - n))

    _bitonic_sort(a, 0, len(a), True, verbose=False, step=1)

    a = [x for x in a if x != float("inf")]

    return a