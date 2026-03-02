/*
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
*/

import java.util.*;

public class QuickSort {

    public static int[] quickSortVerbose(int[] arr) {
        return quickSortVerboseRecursive(arr, 0);
    }

    private static int[] quickSortVerboseRecursive(int[] arr, int depth) {

        String indent = new String(new char[depth]).replace("\0", "  ");
        System.out.println(indent + "quick_sort(" + Arrays.toString(arr) + ")");

        if (arr.length <= 1) {
            return Arrays.copyOf(arr, arr.length);
        }

        int pivot = arr[arr.length / 2];
        System.out.println(indent + "Pivot: " + pivot);

        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int x : arr) {

            System.out.println(indent + "Compare " + x + " with pivot " + pivot);

            if (x < pivot) {
                left.add(x);
                System.out.println(indent + "  -> go left: " + left);
            } else if (x > pivot) {
                right.add(x);
                System.out.println(indent + "  -> go right: " + right);
            } else {
                middle.add(x);
                System.out.println(indent + "  -> go middle: " + middle);
            }
        }

        int[] sortedLeft = quickSortVerboseRecursive(
                left.stream().mapToInt(i -> i).toArray(),
                depth + 1
        );

        int[] sortedRight = quickSortVerboseRecursive(
                right.stream().mapToInt(i -> i).toArray(),
                depth + 1
        );

        int[] result = concatenate(
                sortedLeft,
                middle.stream().mapToInt(i -> i).toArray(),
                sortedRight
        );

        System.out.println(indent + "Combined result: "
                + Arrays.toString(result));

        return result;
    }

    public static int[] quickSort(int[] arr) {

        if (arr.length <= 1) {
            return Arrays.copyOf(arr, arr.length);
        }

        int pivot = arr[arr.length / 2];

        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int x : arr) {
            if (x < pivot) {
                left.add(x);
            } else if (x > pivot) {
                right.add(x);
            } else {
                middle.add(x);
            }
        }

        return concatenate(
                quickSort(left.stream().mapToInt(i -> i).toArray()),
                middle.stream().mapToInt(i -> i).toArray(),
                quickSort(right.stream().mapToInt(i -> i).toArray())
        );
    }

    private static int[] concatenate(int[] left, int[] middle, int[] right) {

        int[] result = new int[left.length + middle.length + right.length];

        int index = 0;

        for (int value : left) {
            result[index++] = value;
        }

        for (int value : middle) {
            result[index++] = value;
        }

        for (int value : right) {
            result[index++] = value;
        }

        return result;
    }
}