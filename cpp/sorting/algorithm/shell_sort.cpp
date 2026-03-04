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

#include <iostream>
#include <vector>

using namespace std;


vector<int> shell_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();
    int step = 1;

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int gap = n / 2;

    while (gap > 0) {
        cout << "\n=== Gap = " << gap << " ===" << endl;

        for (int i = gap; i < n; ++i) {
            int temp = a[i];
            int j = i;

            cout << "\nTake element "
                 << temp << " at index "
                 << i << endl;

            while (j >= gap) {
                cout << "Step " << step
                     << ": compare "
                     << a[j - gap]
                     << " and "
                     << temp << endl;

                if (a[j - gap] > temp) {
                    cout << "  shift "
                         << a[j - gap]
                         << " from index "
                         << j - gap
                         << " to "
                         << j << endl;

                    a[j] = a[j - gap];

                    cout << "  result: ";
                    for (int x : a) cout << x << " ";
                    cout << endl;

                    j -= gap;
                } else {
                    cout << "  no shift needed" << endl;
                    break;
                }

                step += 1;
            }

            a[j] = temp;

            cout << "Insert "
                 << temp
                 << " at index "
                 << j << endl;

            cout << "  result: ";
            for (int x : a) cout << x << " ";
            cout << endl;
        }

        gap /= 2;
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> shell_sort(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
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