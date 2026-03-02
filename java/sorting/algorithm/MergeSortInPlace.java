/*
Merge Sort with In Place Stable Merge Algorithm

This version of merge sort performs merging without using
an additional temporary array.

How it works:
- The array is recursively divided into two halves.
- Each half is sorted recursively.
- The two halves are merged in place.
- When an element from the right half is smaller,
  elements in the left half are shifted to make space.
- This preserves stability while avoiding extra merge storage.

This implementation is educational and focuses on clarity
rather than performance.

Time Complexity:
- Worst Case: O(n^2) due to repeated shifting during in place merge.
- Average Case: O(n^2)
- Best Case: O(n log n) when minimal shifting occurs.

Space Complexity:
- O(1) extra space for merging.
- O(log n) recursion stack space.

Stability:
- Stable because equal elements maintain relative order.
*/

import java.util.Arrays;

public class MergeSortInPlace {

    private static void inplaceMerge(int[] a, int left, int mid, int right) {

        int i = left;
        int j = mid;

        while (i < j && j < right) {

            if (a[i] <= a[j]) {
                i++;
            } else {

                int value = a[j];
                int k = j;

                while (k > i) {
                    a[k] = a[k - 1];
                    k--;
                }

                a[i] = value;

                i++;
                j++;
                mid++;
            }
        }
    }

    private static void mergeSortInplaceRecursive(int[] a, int left, int right) {

        if (right - left <= 1) {
            return;
        }

        int mid = (left + right) / 2;

        mergeSortInplaceRecursive(a, left, mid);
        mergeSortInplaceRecursive(a, mid, right);
        inplaceMerge(a, left, mid, right);
    }

    public static int[] mergeSortInplace(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        mergeSortInplaceRecursive(a, 0, a.length);
        return a;
    }


    private static int inplaceMergeVerbose(
            int[] a,
            int left,
            int mid,
            int right,
            int step
    ) {

        int i = left;
        int j = mid;

        System.out.println("  Merge a[" + left + ":" + mid + "] = "
                + Arrays.toString(Arrays.copyOfRange(a, left, mid))
                + " and a[" + mid + ":" + right + "] = "
                + Arrays.toString(Arrays.copyOfRange(a, mid, right)));

        while (i < j && j < right) {

            System.out.println("  Step " + step + ": compare "
                    + a[i] + " and " + a[j]);

            if (a[i] <= a[j]) {

                System.out.println("    already in order, move left pointer");
                i++;

            } else {

                System.out.println("    " + a[j]
                        + " should come before " + a[i]);

                int value = a[j];

                System.out.println("    save " + value
                        + " and shift left block to the right");

                int k = j;
                while (k > i) {
                    System.out.println("      shift "
                            + a[k - 1]
                            + " from index " + (k - 1)
                            + " to " + k);
                    a[k] = a[k - 1];
                    k--;
                }

                a[i] = value;

                System.out.println("    insert " + value
                        + " at index " + i);
                System.out.println("    result: "
                        + Arrays.toString(a));

                i++;
                j++;
                mid++;
            }

            step++;
        }

        return step;
    }

    private static int mergeSortInplaceVerboseRecursive(
            int[] a,
            int left,
            int right,
            int step
    ) {

        if (right - left <= 1) {
            return step;
        }

        int mid = (left + right) / 2;

        System.out.println("\nSort a[" + left + ":" + mid + "] = "
                + Arrays.toString(Arrays.copyOfRange(a, left, mid)));

        step = mergeSortInplaceVerboseRecursive(a, left, mid, step);

        System.out.println("\nSort a[" + mid + ":" + right + "] = "
                + Arrays.toString(Arrays.copyOfRange(a, mid, right)));

        step = mergeSortInplaceVerboseRecursive(a, mid, right, step);

        System.out.println("\nMerging ranges [" + left + ":" + mid
                + "] and [" + mid + ":" + right + "]");

        step = inplaceMergeVerbose(a, left, mid, right, step);

        return step;
    }

    public static int[] mergeSortInplaceVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);

        System.out.println("Start: " + Arrays.toString(a));

        int step = 1;
        step = mergeSortInplaceVerboseRecursive(a, 0, a.length, step);

        System.out.println("\nSorted: " + Arrays.toString(a));

        return a;
    }
}