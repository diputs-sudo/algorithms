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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> radix_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    if (a.empty())
        return a;

    int max_num = *max_element(a.begin(), a.end());
    int exp = 1;

    while (max_num / exp > 0) {
        cout << "\nSorting by digit at exp = " << exp << endl;

        vector<vector<int>> buckets(10);

        for (int num : a) {
            int digit = (num / exp) % 10;
            cout << "Put " << num
                 << " in bucket " << digit << endl;
            buckets[digit].push_back(num);
        }

        a.clear();

        for (int i = 0; i < 10; ++i) {
            if (!buckets[i].empty()) {
                cout << "Bucket " << i << " -> ";
                for (int x : buckets[i]) cout << x << " ";
                cout << endl;
            }

            for (int num : buckets[i]) {
                a.push_back(num);
            }
        }

        cout << "After collecting: ";
        for (int x : a) cout << x << " ";
        cout << endl;

        exp *= 10;
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> radix_sort(const vector<int>& arr) {
    vector<int> a = arr;

    if (a.empty())
        return a;

    int max_num = *max_element(a.begin(), a.end());
    int exp = 1;

    while (max_num / exp > 0) {
        vector<vector<int>> buckets(10);

        for (int num : a) {
            int digit = (num / exp) % 10;
            buckets[digit].push_back(num);
        }

        a.clear();

        for (auto& bucket : buckets) {
            for (int num : bucket) {
                a.push_back(num);
            }
        }

        exp *= 10;
    }

    return a;
}