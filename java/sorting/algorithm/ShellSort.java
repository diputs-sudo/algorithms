/*
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
*/

import java.util.Arrays;

public class ShellSort {

    public static int[] shellSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;
        int step = 1;

        System.out.println("Start: " + Arrays.toString(a));

        int gap = n / 2;

        while (gap > 0) {

            System.out.println("\n=== Gap = " + gap + " ===");

            for (int i = gap; i < n; i++) {

                int temp = a[i];
                int j = i;

                System.out.println("\nTake element " + temp + " at index " + i);

                while (j >= gap) {

                    System.out.println("Step " + step + ": compare "
                            + a[j - gap] + " and " + temp);

                    if (a[j - gap] > temp) {

                        System.out.println("  shift " + a[j - gap]
                                + " from index " + (j - gap)
                                + " to " + j);

                        a[j] = a[j - gap];

                        System.out.println("  result: "
                                + Arrays.toString(a));

                        j -= gap;

                    } else {

                        System.out.println("  no shift needed");
                        break;
                    }

                    step++;
                }

                a[j] = temp;

                System.out.println("Insert " + temp + " at index " + j);
                System.out.println("  result: "
                        + Arrays.toString(a));
            }

            gap /= 2;
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

    public static int[] shellSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        int n = a.length;

        int gap = n / 2;

        while (gap > 0) {

            for (int i = gap; i < n; i++) {

                int temp = a[i];
                int j = i;

                while (j >= gap && a[j - gap] > temp) {
                    a[j] = a[j - gap];
                    j -= gap;
                }

                a[j] = temp;
            }

            gap /= 2;
        }

        return a;
    }
}