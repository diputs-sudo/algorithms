"""
Quick Sort Algorithm

Quick Sort is a divide and conquer sorting algorithm.

How it works:
- It selects a pivot element from the list.
- It partitions the remaining elements into three groups.
- Elements smaller than the pivot go to the left group.
- Elements equal to the pivot stay in the middle group.
- Elements greater than the pivot go to the right group.
- The left and right groups are sorted recursively.
- The final result is the combination of left, middle, and right groups.

This algorithm is usually very fast in practice.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) in this implementation due to extra lists.

Stability:
- Not stable in general
"""


def quick_sort_verbose(arr, depth=0):
    indent = "  " * depth
    print(f"{indent}quick_sort({arr})")

    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    print(f"{indent}Pivot: {pivot}")

    left = []
    middle = []
    right = []

    for x in arr:
        print(f"{indent}Compare {x} with pivot {pivot}")
        if x < pivot:
            left.append(x)
            print(f"{indent}  -> go left: {left}")
        elif x > pivot:
            right.append(x)
            print(f"{indent}  -> go right: {right}")
        else:
            middle.append(x)
            print(f"{indent}  -> go middle: {middle}")

    sorted_left = quick_sort_verbose(left, depth + 1)
    sorted_right = quick_sort_verbose(right, depth + 1)

    result = sorted_left + middle + sorted_right
    print(f"{indent}Combined result: {result}")
    return result


def quick_sort(arr):
    if len(arr) <= 1:
        return arr[:]

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)