/*
TimSort Algorithm

TimSort is a hybrid sorting algorithm used in Python, Java, and many
other programming languages.

It combines ideas from insertion sort and merge sort.

How it works:
- The array is divided into small sections called runs.
- Each run is sorted using insertion sort.
- The sorted runs are merged together.
- Runs are merged repeatedly until the entire array is sorted.

This approach performs very well on real world data because
many datasets already contain partially sorted sequences.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n) when the data is nearly sorted.

Space Complexity:
- O(n) due to merging operations.

Stability:
- Stable because merging preserves order of equal elements.

Note:
This is a simplified educational version.
The industrial implementation used in Python includes
additional optimizations such as natural run detection,
stack invariants, and galloping mode.
*/

import java.util.*;

public class TimSort {

    private static final int MIN_RUN = 5;

    private static MergeResult mergeVerbose(
            int[] left,
            int[] right,
            int stepStart
    ) {

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        int step = stepStart;

        System.out.println("  Merging "
                + Arrays.toString(left)
                + " and "
                + Arrays.toString(right));

        while (i < left.length && j < right.length) {

            System.out.println("  Step " + step + ": compare "
                    + left[i] + " and " + right[j]);

            if (left[i] <= right[j]) {
                System.out.println("    take " + left[i] + " from left");
                result.add(left[i++]);
            } else {
                System.out.println("    take " + right[j] + " from right");
                result.add(right[j++]);
            }

            System.out.println("    result so far: " + result);
            step++;
        }

        if (i < left.length) {
            System.out.println("  Append remaining from left: "
                    + Arrays.toString(Arrays.copyOfRange(left, i, left.length)));
        }

        if (j < right.length) {
            System.out.println("  Append remaining from right: "
                    + Arrays.toString(Arrays.copyOfRange(right, j, right.length)));
        }

        while (i < left.length) result.add(left[i++]);
        while (j < right.length) result.add(right[j++]);

        int[] merged = result.stream().mapToInt(x -> x).toArray();

        System.out.println("  Merged result: "
                + Arrays.toString(merged));

        return new MergeResult(merged, step);
    }

    // ================= TIM SORT VERBOSE =================

    public static int[] timSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        System.out.println("Start: " + Arrays.toString(a));
        System.out.println("MIN_RUN = " + MIN_RUN);

        System.out.println("\n=== Phase 1: Sort runs with insertion sort ===");

        for (int start = 0; start < n; start += MIN_RUN) {

            int end = Math.min(start + MIN_RUN, n);

            System.out.println("\nRun from index "
                    + start + " to " + (end - 1) + ": "
                    + Arrays.toString(Arrays.copyOfRange(a, start, end)));

            int[] sortedRun =
                    InsertionSort.insertionSortVerbose(
                            Arrays.copyOfRange(a, start, end)
                    );

            System.arraycopy(sortedRun, 0, a, start, sortedRun.length);

            System.out.println("Array after sorting this run: "
                    + Arrays.toString(a));
        }

        System.out.println("\n=== Phase 2: Merge runs ===");

        int size = MIN_RUN;
        int step = 1;

        while (size < n) {

            System.out.println("\n--- Merge size = " + size + " ---");

            for (int left = 0; left < n; left += 2 * size) {

                int mid = Math.min(left + size, n);
                int right = Math.min(left + 2 * size, n);

                int[] leftPart = Arrays.copyOfRange(a, left, mid);
                int[] rightPart = Arrays.copyOfRange(a, mid, right);

                System.out.println("\nMerging slices a["
                        + left + ":" + mid + "] and a["
                        + mid + ":" + right + "]");

                MergeResult mergeResult =
                        mergeVerbose(leftPart, rightPart, step);

                step = mergeResult.step;

                System.arraycopy(
                        mergeResult.merged,
                        0,
                        a,
                        left,
                        mergeResult.merged.length
                );

                System.out.println("Array after merge: "
                        + Arrays.toString(a));
            }

            size *= 2;
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

    // ================= MERGE (NON VERBOSE) =================

    private static int[] merge(int[] left, int[] right) {

        List<Integer> result = new ArrayList<>();
        int i = 0, j = 0;

        while (i < left.length && j < right.length) {

            if (left[i] <= right[j]) {
                result.add(left[i++]);
            } else {
                result.add(right[j++]);
            }
        }

        while (i < left.length) result.add(left[i++]);
        while (j < right.length) result.add(right[j++]);

        return result.stream().mapToInt(x -> x).toArray();
    }

    public static int[] timSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        for (int start = 0; start < n; start += MIN_RUN) {

            int end = Math.min(start + MIN_RUN, n);

            int[] sortedRun =
                    InsertionSort.insertionSort(
                            Arrays.copyOfRange(a, start, end)
                    );

            System.arraycopy(sortedRun, 0, a, start, sortedRun.length);
        }

        int size = MIN_RUN;

        while (size < n) {

            for (int left = 0; left < n; left += 2 * size) {

                int mid = Math.min(left + size, n);
                int right = Math.min(left + 2 * size, n);

                int[] merged = merge(
                        Arrays.copyOfRange(a, left, mid),
                        Arrays.copyOfRange(a, mid, right)
                );

                System.arraycopy(merged, 0, a, left, merged.length);
            }

            size *= 2;
        }

        return a;
    }

    // Helper class for verbose merge result
    private static class MergeResult {
        int[] merged;
        int step;

        MergeResult(int[] merged, int step) {
            this.merged = merged;
            this.step = step;
        }
    }
}