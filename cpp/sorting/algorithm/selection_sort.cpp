/*
Selection Sort Algorithm

Selection Sort is a simple comparison based sorting algorithm.

How it works:
- It divides the list into a sorted portion and an unsorted portion.
- It repeatedly finds the smallest element from the unsorted portion.
- It swaps that element with the first unsorted position.
- The sorted portion grows one element at a time from the beginning.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n^2)

Space Complexity:
- O(1) since it sorts in place.
*/

#include <iostream>
#include <vector>

using namespace std;


vector<int> selection_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();
    int step = 1;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    for (int i = 0; i < n; ++i) {
        int min_idx = i;

        cout << "\nSelect position " << i << endl;

        for (int j = i + 1; j < n; ++j) {
            cout << "Step " << step << ": compare "
                 << a[j] << " and " << a[min_idx] << endl;

            if (a[j] < a[min_idx]) {
                min_idx = j;
                cout << "  new min is "
                     << a[min_idx]
                     << " at index " << min_idx << endl;
            }

            step += 1;
        }

        if (min_idx != i) {
            cout << "Swap " << a[i]
                 << " and " << a[min_idx] << endl;

            swap(a[i], a[min_idx]);

            cout << "  result: ";
            for (int x : a) cout << x << " ";
            cout << endl;
        } else {
            cout << "No swap needed" << endl;
        }
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> selection_sort(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }

    return a;
}