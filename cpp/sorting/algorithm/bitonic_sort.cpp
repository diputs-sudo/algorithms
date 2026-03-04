/*
Bitonic Sort Algorithm

Bitonic Sort is a comparison based sorting algorithm commonly used in
parallel computing environments.

How it works:
- It recursively builds bitonic sequences.
- A bitonic sequence first increases and then decreases.
- These sequences are merged using compare and swap operations.
- Repeated merging produces a fully sorted sequence.

Classic Bitonic Sort assumes the input size is a power of two.

This educational implementation:
- Automatically pads the list to the next power of two using infinity.
- Removes the padding after sorting.
- Supports a verbose mode for visualization.

Time Complexity:
- Worst Case: O(n log^2 n)
- Average Case: O(n log^2 n)
- Best Case: O(n log^2 n)

Space Complexity:
- O(n) due to padding and recursive structure.

Stability:
- Not stable.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


bool _is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


int _next_power_of_two(int n) {
    return 1 << (int)ceil(log2(n));
}


void _compare_and_swap(vector<double>& a, int i, int j, bool ascending, bool verbose = false, int step = 0) {
    if (verbose) {
        string direction = ascending ? "ascending" : "descending";
        cout << "Step " << step << ": compare " << a[i] << " and " << a[j]
             << " (" << direction << ")" << endl;
    }

    if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
        if (verbose) {
            cout << "  swap " << a[i] << " and " << a[j] << endl;
        }

        swap(a[i], a[j]);

        if (verbose) {
            cout << "  result: ";
            for (double x : a) cout << x << " ";
            cout << endl;
        }
    } else {
        if (verbose) {
            cout << "  no swap" << endl;
        }
    }
}


int _bitonic_merge(vector<double>& a, int low, int cnt, bool ascending, bool verbose = false, int step = 1) {
    if (cnt > 1) {
        int k = cnt / 2;

        for (int i = low; i < low + k; ++i) {
            _compare_and_swap(a, i, i + k, ascending, verbose, step);
            step += 1;
        }

        step = _bitonic_merge(a, low, k, ascending, verbose, step);
        step = _bitonic_merge(a, low + k, k, ascending, verbose, step);
    }

    return step;
}


int _bitonic_sort(vector<double>& a, int low, int cnt, bool ascending, bool verbose = false, int step = 1) {
    if (cnt > 1) {
        int k = cnt / 2;

        if (verbose) {
            string direction = ascending ? "ascending" : "descending";
            cout << "\nBuild bitonic sequence from index "
                 << low << " count " << cnt
                 << " (" << direction << ")" << endl;
        }

        step = _bitonic_sort(a, low, k, true, verbose, step);
        step = _bitonic_sort(a, low + k, k, false, verbose, step);
        step = _bitonic_merge(a, low, cnt, ascending, verbose, step);
    }

    return step;
}


vector<double> bitonic_sort_verbose(const vector<double>& arr) {
    vector<double> a = arr;
    int n = a.size();

    cout << "Start: ";
    for (double x : a) cout << x << " ";
    cout << endl;

    int target = _next_power_of_two(n);
    if (target != n) {
        cout << "Note: Bitonic sort works best when length is a power of two." << endl;
        cout << "Padding array from length " << n
             << " to " << target << " using infinity." << endl;

        double pad_value = numeric_limits<double>::infinity();
        a.insert(a.end(), target - n, pad_value);

        cout << "Working array: ";
        for (double x : a) cout << x << " ";
        cout << endl;
    }

    _bitonic_sort(a, 0, a.size(), true, true, 1);

    double inf = numeric_limits<double>::infinity();
    vector<double> result;
    for (double x : a) {
        if (x != inf) result.push_back(x);
    }

    cout << "\nSorted: ";
    for (double x : result) cout << x << " ";
    cout << endl;

    return result;
}


vector<double> bitonic_sort(const vector<double>& arr) {
    vector<double> a = arr;
    int n = a.size();

    int target = _next_power_of_two(n);
    if (target != n) {
        double pad_value = numeric_limits<double>::infinity();
        a.insert(a.end(), target - n, pad_value);
    }

    _bitonic_sort(a, 0, a.size(), true, false, 1);

    double inf = numeric_limits<double>::infinity();
    vector<double> result;
    for (double x : a) {
        if (x != inf) result.push_back(x);
    }

    return result;
}