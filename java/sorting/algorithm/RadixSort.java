/*
Radix Sort Algorithm

Radix Sort is a non comparison based sorting algorithm.

How it works:
- It processes numbers digit by digit.
- It groups numbers based on the current digit.
- It starts from the least significant digit.
- It moves toward the most significant digit.
- After processing all digits, the list becomes sorted.

This version uses base 10 buckets and works for non negative integers.

Time Complexity:
- Worst Case: O(d x (n + k))
- Average Case: O(d x (n + k))
- Best Case: O(d x (n + k))

Here n is the number of elements, d is the number of digits,
and k is the range of each digit which is 0 to 9 in base 10.

Space Complexity:
- O(n + k) due to bucket storage.

Stability:
- Stable when bucket collection preserves order.
*/

import java.util.*;

public class RadixSort {

    public static int[] radixSortVerbose(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);
        System.out.println("Start: " + Arrays.toString(a));

        if (a.length == 0) {
            return a;
        }

        int maxNum = Arrays.stream(a).max().getAsInt();
        int exp = 1;

        while (maxNum / exp > 0) {

            System.out.println("\nSorting by digit at exp = " + exp);

            List<List<Integer>> buckets = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                buckets.add(new ArrayList<>());
            }

            for (int num : a) {
                int digit = (num / exp) % 10;
                System.out.println("Put " + num + " in bucket " + digit);
                buckets.get(digit).add(num);
            }

            List<Integer> collected = new ArrayList<>();

            for (int i = 0; i < buckets.size(); i++) {
                List<Integer> bucket = buckets.get(i);
                if (!bucket.isEmpty()) {
                    System.out.println("Bucket " + i + " -> " + bucket);
                }
                collected.addAll(bucket);
            }

            a = collected.stream().mapToInt(i -> i).toArray();

            System.out.println("After collecting: "
                    + Arrays.toString(a));

            exp *= 10;
        }

        System.out.println("\nSorted: " + Arrays.toString(a));
        return a;
    }

    public static int[] radixSort(int[] arr) {

        int[] a = Arrays.copyOf(arr, arr.length);

        if (a.length == 0) {
            return a;
        }

        int maxNum = Arrays.stream(a).max().getAsInt();
        int exp = 1;

        while (maxNum / exp > 0) {

            List<List<Integer>> buckets = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                buckets.add(new ArrayList<>());
            }

            for (int num : a) {
                int digit = (num / exp) % 10;
                buckets.get(digit).add(num);
            }

            List<Integer> collected = new ArrayList<>();

            for (List<Integer> bucket : buckets) {
                collected.addAll(bucket);
            }

            a = collected.stream().mapToInt(i -> i).toArray();

            exp *= 10;
        }

        return a;
    }
}