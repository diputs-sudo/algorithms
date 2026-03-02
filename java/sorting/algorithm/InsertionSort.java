/*
Insertion Sort Algorithm

Insertion Sort is a simple comparison based sorting algorithm.

How it works:
- It builds the sorted list one element at a time.
- It takes the next element and compares it with elements before it.
- Larger elements are shifted to the right.
- The current element is inserted into its correct position.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n) when the list is already sorted.

Space complexity:
- O(1) since it sorts in place.
*/

import java.util.Arrays;

public class InsertionSort {

    public static int[] insertionSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int step = 1;

        System.out.println("Start: " + Arrays.toString(a));

        for (int i = 1; i < a.length; i++) {

            int key = a[i];
            int j = i - 1;

            System.out.println("\nTake element " + key + " at index " + i);

            while (j >= 0 && a[j] > key) {

                System.out.println("Step " + step + ": compare "
                        + a[j] + " and " + key
                        + " -> shift " + a[j] + " right");

                a[j + 1] = a[j];

                System.out.println("  result: " + Arrays.toString(a));

                j--;
                step++;
            }

            a[j + 1] = key;

            System.out.println("Insert " + key + " at position " + (j + 1));
            System.out.println("  result: " + Arrays.toString(a));
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

    public static int[] insertionSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);

        for (int i = 1; i < a.length; i++) {

            int key = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = key;
        }

        return a;
    }
}