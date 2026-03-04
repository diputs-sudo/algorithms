/*
Bubble Sort Algorithm

Bubble Sort is a simple comparison-based sorting algorithm.

How it works:
- It repeatedly steps through the list.
- Compares adjacent elements.
- Swaps them if they are in the wrong order.
- After each full pass, the largest unsorted element
  "bubbles up" to its correct position at the end.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2) (without optimization)
*/

#include <iostream>
#include <vector>

using namespace std;

void print_array(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> bubble_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();
    int step = 1;

    cout << "Start: ";
    print_array(a);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Step " << step << ": compare "
                 << a[j] << " and " << a[j + 1] << endl;

            if (a[j] > a[j + 1]) {
                cout << "  swap " << a[j] << " and "
                     << a[j + 1] << endl;

                swap(a[j], a[j + 1]);

                cout << "  result: ";
                print_array(a);
            } else {
                cout << "  no swap" << endl;
            }
            step++;
        }
    }

    cout << "Sorted: ";
    print_array(a);
    return a;
}

vector<int> bubble_sort(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    return a;
}