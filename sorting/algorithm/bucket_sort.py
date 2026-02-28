"""
Bucket Sort Algorithm

Bucket Sort is a distribution based sorting algorithm.

How it works:
- It divides elements into several groups called buckets.
- Each bucket holds values within a specific range.
- Elements are distributed into buckets based on their value.
- Each bucket is sorted individually.
- All buckets are combined to produce the final sorted list.

This algorithm performs well when the input values are evenly distributed.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n + k)
- Best Case: O(n + k)

Here n is the number of elements and k is the number of buckets.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Depends on the sorting method used inside each bucket.
"""


def bucket_sort_verbose(arr, bucket_size=5):
    if not arr:
        return []

    a = arr[:]
    print("Start:", a)

    min_val = min(a)
    max_val = max(a)

    print("Min:", min_val, "Max:", max_val)

    bucket_count = (max_val - min_val) // bucket_size + 1
    buckets = [[] for _ in range(bucket_count)]

    print(f"\nCreated {bucket_count} buckets")

    print("\nDistributing into buckets...")
    for num in a:
        index = (num - min_val) // bucket_size
        print(f"Put {num} into bucket {index}")
        buckets[index].append(num)

    print("\nBuckets before sorting:")
    for i, b in enumerate(buckets):
        print(f"Bucket {i}:", b)

    print("\nSorting each bucket and collecting...")
    result = []
    for i, b in enumerate(buckets):
        print(f"Sort bucket {i}: {b}")
        b.sort()
        print(f"  sorted bucket {i}: {b}")
        for num in b:
            result.append(num)
            print("  result:", result)

    print("\nSorted:", result)
    return result


def bucket_sort(arr, bucket_size=5):
    if not arr:
        return []

    a = arr[:]
    min_val = min(a)
    max_val = max(a)

    bucket_count = (max_val - min_val) // bucket_size + 1
    buckets = [[] for _ in range(bucket_count)]

    for num in a:
        index = (num - min_val) // bucket_size
        buckets[index].append(num)

    result = []
    for b in buckets:
        b.sort()
        result.extend(b)

    return result