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

#include <iostream>
#include <vector>

using namespace std;


vector<int> merge_sort_verbose(const vector<int>& arr, int depth = 0) {
    string indent(depth * 2, ' ');

    cout << indent << "merge_sort(";
    for (int x : arr) cout << x << " ";
    cout << ")" << endl;

    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = merge_sort_verbose(left, depth + 1);
    right = merge_sort_verbose(right, depth + 1);

    vector<int> result;
    int i = 0, j = 0;

    cout << indent << "Merging ";
    for (int x : left) cout << x << " ";
    cout << "and ";
    for (int x : right) cout << x << " ";
    cout << endl;

    while (i < left.size() && j < right.size()) {
        cout << indent << "Compare "
             << left[i] << " and " << right[j] << endl;

        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i += 1;
        } else {
            result.push_back(right[j]);
            j += 1;
        }

        cout << indent << "  result now: ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i += 1;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j += 1;
    }

    cout << indent << "Merged into: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return result;
}


vector<int> merge_sort(const vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i += 1;
        } else {
            result.push_back(right[j]);
            j += 1;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i += 1;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j += 1;
    }

    return result;
}