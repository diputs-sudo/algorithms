"""
Counting Sort Algorithm

Counting Sort is a non comparison based sorting algorithm.

How it works:
- It counts how many times each value appears in the input.
- It stores those counts in a separate array.
- It rebuilds the sorted list using the stored frequencies.

This algorithm works best when the range of input values is not very large.

Time Complexity:
- Worst Case: O(n + k)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the range of values.

Space Complexity:
- O(k) due to the counting array.

Stability:
- This basic version is not stable.
- A modified version can be made stable.
"""


def counting_sort_verbose(arr):
    if not arr:
        return []

    a = arr[:]
    print("Start:", a)

    max_val = max(a)
    print("Max value:", max_val)

    count = [0] * (max_val + 1)

    print("\nCounting occurrences...")
    for num in a:
        count[num] += 1
        print(f"Count[{num}] -> {count[num]}")

    print("\nCount array:", count)

    result = []
    print("\nBuilding sorted array...")
    for value, freq in enumerate(count):
        if freq > 0:
            print(f"Add {value} x {freq}")
        for _ in range(freq):
            result.append(value)
            print("  result:", result)

    print("\nSorted:", result)
    return result


def counting_sort(arr):
    if not arr:
        return []

    a = arr[:]
    max_val = max(a)

    count = [0] * (max_val + 1)
    for num in a:
        count[num] += 1

    result = []
    for value, freq in enumerate(count):
        for _ in range(freq):
            result.append(value)

    return result