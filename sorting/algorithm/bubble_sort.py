"""
Bubble Sort Algorithm

Bubble Sort is a simple comparison-based sorting algorithm.

How it works:
- It repeatedly steps through the list.
- Compares adjacent elements.
- Swaps them if they are in the wrong order.
- After each full pass, the largest unsorted element
  "bubbles up" to its correct position at the end.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2) (without optimization)
"""


def bubble_sort_verbose(arr):
    a = arr[:]  
    n = len(a)
    step = 1

    print("Start:", a)

    for i in range(n):
        for j in range(0, n - i - 1):
            print(f"Step {step}: compare {a[j]} and {a[j+1]}")
            if a[j] > a[j + 1]:
                print(f"  swap {a[j]} and {a[j+1]}")
                a[j], a[j + 1] = a[j + 1], a[j]
                print("  result:", a)
            else:
                print("  no swap")
            step += 1

    print("Sorted:", a)
    return a


def bubble_sort(arr):
    a = arr[:]  
    n = len(a)

    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]

    return a