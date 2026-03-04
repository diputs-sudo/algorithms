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

#include <iostream>
#include <vector>

using namespace std;


vector<int> quick_sort_verbose(const vector<int>& arr, int depth = 0) {
    string indent(depth * 2, ' ');

    cout << indent << "quick_sort(";
    for (int x : arr) cout << x << " ";
    cout << ")" << endl;

    if (arr.size() <= 1)
        return arr;

    int pivot = arr[arr.size() / 2];
    cout << indent << "Pivot: " << pivot << endl;

    vector<int> left;
    vector<int> middle;
    vector<int> right;

    for (int x : arr) {
        cout << indent << "Compare " << x
             << " with pivot " << pivot << endl;

        if (x < pivot) {
            left.push_back(x);
            cout << indent << "  -> go left: ";
            for (int v : left) cout << v << " ";
            cout << endl;
        }
        else if (x > pivot) {
            right.push_back(x);
            cout << indent << "  -> go right: ";
            for (int v : right) cout << v << " ";
            cout << endl;
        }
        else {
            middle.push_back(x);
            cout << indent << "  -> go middle: ";
            for (int v : middle) cout << v << " ";
            cout << endl;
        }
    }

    vector<int> sorted_left =
        quick_sort_verbose(left, depth + 1);

    vector<int> sorted_right =
        quick_sort_verbose(right, depth + 1);

    vector<int> result;

    result.insert(result.end(),
                  sorted_left.begin(), sorted_left.end());

    result.insert(result.end(),
                  middle.begin(), middle.end());

    result.insert(result.end(),
                  sorted_right.begin(), sorted_right.end());

    cout << indent << "Combined result: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return result;
}


vector<int> quick_sort(const vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    int pivot = arr[arr.size() / 2];

    vector<int> left;
    vector<int> middle;
    vector<int> right;

    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }

    vector<int> result;

    vector<int> sorted_left = quick_sort(left);
    vector<int> sorted_right = quick_sort(right);

    result.insert(result.end(),
                  sorted_left.begin(), sorted_left.end());

    result.insert(result.end(),
                  middle.begin(), middle.end());

    result.insert(result.end(),
                  sorted_right.begin(), sorted_right.end());

    return result;
}