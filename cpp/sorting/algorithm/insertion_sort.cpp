/*
Insertion Sort Algorithm

Insertion Sort is a simple comparison based sorting algorithm.

How it works:
- It builds the sorted list one element at a time.
- It takes the next element and compares it with elements before it.
- Larger elements are shifted to the right.
- The current element is inserted into its correct position.

Time Complexity:
- Worst Case: O(n^2)
- Average Case: O(n^2)
- Best Case: O(n) when the list is already sorted.

Space complexity:
- O(1) since it sorts in place.
*/

#include <iostream>
#include <vector>

using namespace std;


vector<int> insertion_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int step = 1;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    for (int i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;

        cout << "\nTake element " << key
             << " at index " << i << endl;

        while (j >= 0 && a[j] > key) {
            cout << "Step " << step << ": compare "
                 << a[j] << " and " << key
                 << " -> shift " << a[j] << " right" << endl;

            a[j + 1] = a[j];

            cout << "  result: ";
            for (int x : a) cout << x << " ";
            cout << endl;

            j -= 1;
            step += 1;
        }

        a[j + 1] = key;

        cout << "Insert " << key
             << " at position " << j + 1 << endl;

        cout << "  result: ";
        for (int x : a) cout << x << " ";
        cout << endl;
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> insertion_sort(const vector<int>& arr) {
    vector<int> a = arr;

    for (int i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j -= 1;
        }

        a[j + 1] = key;
    }

    return a;
}