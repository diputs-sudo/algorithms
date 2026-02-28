"""
Shell Sort Algorithm

Shell Sort is an optimization of insertion sort.

How it works:
- It starts by comparing elements that are far apart using a gap value.
- The gap is gradually reduced after each pass.
- Elements are partially sorted at each gap level.
- When the gap becomes 1, the algorithm performs a final insertion sort pass.

This approach moves elements closer to their correct positions early,
which improves performance compared to regular insertion sort.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: depends on the gap sequence and is often around O(n^1.5)
- Best Case: better than O(n^2) depending on input and gap sequence

Space Complexity:
- O(1) since it sorts in place.

Stability:
- Not stable in general.
"""


def shell_sort_verbose(arr):
    a = arr[:]
    n = len(a)
    step = 1

    print("Start:", a)

    gap = n // 2

    while gap > 0:
        print(f"\n=== Gap = {gap} ===")

        for i in range(gap, n):
            temp = a[i]
            j = i

            print(f"\nTake element {temp} at index {i}")

            while j >= gap:
                print(f"Step {step}: compare {a[j - gap]} and {temp}")
                if a[j - gap] > temp:
                    print(f"  shift {a[j - gap]} from index {j - gap} to {j}")
                    a[j] = a[j - gap]
                    print("  result:", a)
                    j -= gap
                else:
                    print("  no shift needed")
                    break
                step += 1

            a[j] = temp
            print(f"Insert {temp} at index {j}")
            print("  result:", a)

        gap //= 2

    print("\nSorted:", a)
    return a


def shell_sort(arr):
    a = arr[:]
    n = len(a)

    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = a[i]
            j = i

            while j >= gap and a[j - gap] > temp:
                a[j] = a[j - gap]
                j -= gap

            a[j] = temp

        gap //= 2

    return a
