"""
Selection Sort Algorithm

Selection Sort is a simple comparison based sorting algorithm.

How it works:
It divides the list into a sorted and an unsorted portion.
It repeatedly finds the smallest element in the unsorted portion.
It swaps that element with the first unsorted position.
The sorted portion grows from left to right.

Time Complexity:
Worst Case: O(n^2)
Average Case: O(n^2)
Best Case: O(n^2)

Space Complexity:
O(1) because it sorts in place.

This version includes:
1. selection_sort_verbose() -> shows each comparison and swap step by step.
2. selection_sort() -> a clean version without print statements.
"""


def selection_sort_verbose(arr):
    a = arr[:]
    n = len(a)
    step = 1

    print("Start:", a)

    for i in range(n):
        min_idx = i
        print(f"\nSelect position {i}")

        for j in range(i + 1, n):
            print(f"Step {step}: compare {a[j]} and {a[min_idx]}")
            if a[j] < a[min_idx]:
                min_idx = j
                print(f"  new min is {a[min_idx]} at index {min_idx}")
            step += 1

        if min_idx != i:
            print(f"Swap {a[i]} and {a[min_idx]}")
            a[i], a[min_idx] = a[min_idx], a[i]
            print("  result:", a)
        else:
            print("No swap needed")

    print("\nSorted:", a)
    return a


def selection_sort(arr):
    a = arr[:]
    n = len(a)

    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j

        if min_idx != i:
            a[i], a[min_idx] = a[min_idx], a[i]

    return a