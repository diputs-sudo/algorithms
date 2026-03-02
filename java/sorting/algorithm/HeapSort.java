/*
Heap Sort Algorithm

Heap Sort is a comparison based sorting algorithm that uses a binary heap data structure.

How it works:
- It first builds a max heap from the input list.
- The largest element is stored at the root of the heap.
- The root element is swapped with the last element.
- The heap size is reduced and heap property is restored.
- This process repeats until the list is fully sorted.

This approach guarantees consistent performance.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(1) since it sorts in place.

Stability:
- Not stable.
*/

import java.util.Arrays;

public class HeapSort {

    public static int[] heapSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        System.out.println("Start: " + Arrays.toString(a));

        System.out.println("\nBuilding max heap...");
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyVerbose(a, n, i);
        }

        System.out.println("\nExtracting elements...");
        for (int i = n - 1; i > 0; i--) {

            System.out.println("Swap max " + a[0] + " with " + a[i]);

            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            System.out.println("  result: " + Arrays.toString(a));

            heapifyVerbose(a, i, 0);
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

    private static void heapifyVerbose(int[] a, int n, int i) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n) {
            System.out.println("Compare parent " + a[i]
                    + " with left child " + a[left]);
        }

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n) {
            System.out.println("Compare current max "
                    + a[largest] + " with right child " + a[right]);
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != i) {

            System.out.println("Swap " + a[i] + " and " + a[largest]);

            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            System.out.println("  result: " + Arrays.toString(a));

            heapifyVerbose(a, n, largest);
        }
    }

    public static int[] heapSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }

        for (int i = n - 1; i > 0; i--) {

            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            heapify(a, i, 0);
        }

        return a;
    }

    private static void heapify(int[] a, int n, int i) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != i) {

            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            heapify(a, n, largest);
        }
    }
}