"""
Merge Sort Algorithm

Merge Sort is a divide and conquer sorting algorithm.

How it works:
- It divides the list into two halves.
- Each half is sorted recursively.
- The sorted halves are merged together.
- The merging step compares elements from both halves and builds a new sorted list.

This approach ensures consistent performance regardless of input order.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to temporary arrays used during merging.

Stability:
- Stable because equal elements preserve their original order
"""


def merge_sort_verbose(arr, depth=0):
    indent = "  " * depth
    print(f"{indent}merge_sort({arr})")

    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort_verbose(arr[:mid], depth + 1)
    right = merge_sort_verbose(arr[mid:], depth + 1)

    result = []
    i = j = 0

    print(f"{indent}Merging {left} and {right}")

    while i < len(left) and j < len(right):
        print(f"{indent}Compare {left[i]} and {right[j]}")
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
        print(f"{indent}  result now: {result}")

    result.extend(left[i:])
    result.extend(right[j:])

    print(f"{indent}Merged into: {result}")
    return result


def merge_sort(arr):
    if len(arr) <= 1:
        return arr[:]

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result