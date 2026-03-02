/*
Tournament Sort Algorithm

Tournament Sort is a comparison based sorting algorithm inspired by
a knockout tournament structure.

How it works:
- Elements are placed in the leaves of a binary tree.
- Each internal node stores the minimum of its two children.
- The root always contains the smallest element in the structure.
- The minimum element is extracted and replaced with infinity.
- The tree is updated from the leaf to the root.
- The process repeats until all elements are extracted.

This approach simulates repeatedly selecting the minimum efficiently.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to the tournament tree structure.

Stability:
- Not stable in general.
*/

import java.util.*;

public class TournamentSort {

    private static BuildResult buildTree(int[] a) {

        int n = a.length;

        int size = 1 << (32 - Integer.numberOfLeadingZeros(n - 1));
        int offset = size;

        double[] tree = new double[2 * size];
        Arrays.fill(tree, Double.POSITIVE_INFINITY);

        for (int i = 0; i < n; i++) {
            tree[offset + i] = a[i];
        }

        for (int i = offset - 1; i > 0; i--) {
            tree[i] = Math.min(tree[2 * i], tree[2 * i + 1]);
        }

        return new BuildResult(tree, offset);
    }

    private static void updateTree(double[] tree, int index) {

        int i = index / 2;

        while (i >= 1) {
            tree[i] = Math.min(tree[2 * i], tree[2 * i + 1]);
            i /= 2;
        }
    }

    public static int[] tournamentSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        System.out.println("Start: " + Arrays.toString(a));

        BuildResult build = buildTree(a);
        double[] tree = build.tree;
        int offset = build.offset;

        System.out.println("\nInitial tournament tree as array:");
        System.out.println(Arrays.toString(tree));

        List<Integer> result = new ArrayList<>();
        int step = 1;

        for (int count = 0; count < n; count++) {

            double winner = tree[1];

            System.out.println("\nStep " + step +
                    ": current winner is " + winner);

            result.add((int) winner);

            int i = 1;

            while (i < offset) {

                int left = 2 * i;
                int right = 2 * i + 1;

                if (tree[left] == winner) {
                    i = left;
                } else {
                    i = right;
                }
            }

            System.out.println("  Winner found at leaf index "
                    + i + ", replacing with infinity");

            tree[i] = Double.POSITIVE_INFINITY;

            updateTree(tree, i);

            System.out.println("  Tree after update:");
            System.out.println("  " + Arrays.toString(tree));
            System.out.println("  Result so far: " + result);

            step++;
        }

        int[] sorted = result.stream().mapToInt(x -> x).toArray();

        System.out.println("\nSorted: " + Arrays.toString(sorted));

        return sorted;
    }

    public static int[] tournamentSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        BuildResult build = buildTree(a);
        double[] tree = build.tree;
        int offset = build.offset;

        List<Integer> result = new ArrayList<>();

        for (int count = 0; count < n; count++) {

            double winner = tree[1];
            result.add((int) winner);

            int i = 1;

            while (i < offset) {

                int left = 2 * i;
                int right = 2 * i + 1;

                if (tree[left] == winner) {
                    i = left;
                } else {
                    i = right;
                }
            }

            tree[i] = Double.POSITIVE_INFINITY;
            updateTree(tree, i);
        }

        return result.stream().mapToInt(x -> x).toArray();
    }

    private static class BuildResult {
        double[] tree;
        int offset;

        BuildResult(double[] tree, int offset) {
            this.tree = tree;
            this.offset = offset;
        }
    }
}