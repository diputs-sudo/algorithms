"""
IntroSort Algorithm

IntroSort is a hybrid sorting algorithm that combines
Quick Sort, Heap Sort, and Insertion Sort.

How it works:
- It begins with Quick Sort.
- If recursion depth becomes too large, it switches to Heap Sort.
- For small subarrays, it uses Insertion Sort.
- This combination guarantees both speed and worst case safety.

The depth limit is typically set to 2 x log2(n).
If that depth is exceeded, Heap Sort is used to avoid
Quick Sort worst case behavior.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) in this implementation due to extra lists.

Stability:
- Not stable.

Note:
IntroSort is used in many standard library implementations
because it provides fast average performance while also
guaranteeing O(n log n) worst case time.
"""


from algorithm.heap_sort import heap_sort
from algorithm.insertion_sort import insertion_sort


def intro_sort_verbose(arr):
    print("Start:", arr)
    max_depth = 2 * (len(arr).bit_length())
    result = _intro_sort_verbose(arr[:], max_depth, depth=0)
    print("\nSorted:", result)
    return result


def _intro_sort_verbose(a, max_depth, depth):
    indent = "  " * depth
    print(f"{indent}IntroSort({a}), max_depth={max_depth}")

    if len(a) <= 16:
        print(f"{indent}Use insertion sort for small array")
        return insertion_sort(a)

    if max_depth == 0:
        print(f"{indent}Depth limit reached, switch to heap sort")
        return heap_sort(a)

    pivot = a[len(a) // 2]

    left = [x for x in a if x < pivot]
    middle = [x for x in a if x == pivot]
    right = [x for x in a if x > pivot]

    return (
        _intro_sort_verbose(left, max_depth - 1, depth + 1)
        + middle
        + _intro_sort_verbose(right, max_depth - 1, depth + 1)
    )


def intro_sort(arr):
    max_depth = 2 * (len(arr).bit_length())
    return _intro_sort(arr[:], max_depth)


def _intro_sort(a, max_depth):
    if len(a) <= 16:
        return insertion_sort(a)

    if max_depth == 0:
        return heap_sort(a)

    pivot = a[len(a) // 2]
    left = [x for x in a if x < pivot]
    middle = [x for x in a if x == pivot]
    right = [x for x in a if x > pivot]

    return _intro_sort(left, max_depth - 1) + middle + _intro_sort(right, max_depth - 1)