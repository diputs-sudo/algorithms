/*
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
*/

import java.util.*;

public class MergeSort {

    public static int[] mergeSortVerbose(int[] arr) {
        return mergeSortVerboseRecursive(arr, 0);
    }

    private static int[] mergeSortVerboseRecursive(int[] arr, int depth) {

        String indent = new String(new char[depth]).replace("\0", "  ");
        System.out.println(indent + "merge_sort(" + Arrays.toString(arr) + ")");

        if (arr.length <= 1) {
            return Arrays.copyOf(arr, arr.length);
        }

        int mid = arr.length / 2;

        int[] left = mergeSortVerboseRecursive(
                Arrays.copyOfRange(arr, 0, mid),
                depth + 1
        );

        int[] right = mergeSortVerboseRecursive(
                Arrays.copyOfRange(arr, mid, arr.length),
                depth + 1
        );

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;

        System.out.println(indent + "Merging "
                + Arrays.toString(left)
                + " and "
                + Arrays.toString(right));

        while (i < left.length && j < right.length) {

            System.out.println(indent + "Compare "
                    + left[i] + " and " + right[j]);

            if (left[i] <= right[j]) {
                result.add(left[i]);
                i++;
            } else {
                result.add(right[j]);
                j++;
            }

            System.out.println(indent + "  result now: " + result);
        }

        while (i < left.length) {
            result.add(left[i++]);
        }

        while (j < right.length) {
            result.add(right[j++]);
        }

        int[] merged = result.stream().mapToInt(x -> x).toArray();

        System.out.println(indent + "Merged into: "
                + Arrays.toString(merged));

        return merged;
    }

    public static int[] mergeSort(int[] arr) {

        if (arr.length <= 1) {
            return Arrays.copyOf(arr, arr.length);
        }

        int mid = arr.length / 2;

        int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        int[] right = mergeSort(Arrays.copyOfRange(arr, mid, arr.length));

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;

        while (i < left.length && j < right.length) {

            if (left[i] <= right[j]) {
                result.add(left[i++]);
            } else {
                result.add(right[j++]);
            }
        }

        while (i < left.length) {
            result.add(left[i++]);
        }

        while (j < right.length) {
            result.add(right[j++]);
        }

        return result.stream().mapToInt(x -> x).toArray();
    }
}