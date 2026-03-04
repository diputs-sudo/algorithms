/*
Tournament Sort Algorithm

Tournament Sort is a comparison based sorting algorithm inspired by
a knockout tournament structure.

How it works:
- Elements are placed in the leaves of a binary tree.
- Each internal node stores the minimum of its two children.
- The root always contains the smallest element in the structure.
- The minimum element is extracted and replaced with infinity.
- The tree is updated from the leaf to the root.
- The process repeats until all elements are extracted.

This approach simulates repeatedly selecting the minimum efficiently.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) due to the tournament tree structure.

Stability:
- Not stable in general.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


tuple<vector<double>, int, int> _build_tree(const vector<double>& a) {
    int n = a.size();
    int size = 1 << (int)ceil(log2(n > 0 ? n : 1));
    int offset = size;

    vector<double> tree(2 * size,
        numeric_limits<double>::infinity());

    for (int i = 0; i < n; ++i) {
        tree[offset + i] = a[i];
    }

    for (int i = offset - 1; i > 0; --i) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    return {tree, offset, size};
}


void _update_tree(vector<double>& tree, int index) {
    int i = index / 2;

    while (i >= 1) {
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        i /= 2;
    }
}


vector<double> tournament_sort_verbose(const vector<double>& arr) {
    vector<double> a = arr;
    int n = a.size();

    cout << "Start: ";
    for (double x : a) cout << x << " ";
    cout << endl;

    auto [tree, offset, size] = _build_tree(a);

    cout << "\nInitial tournament tree as array:" << endl;
    cout << "[ ";
    for (double x : tree) cout << x << " ";
    cout << "]" << endl;

    vector<double> result;
    int step = 1;

    for (int t = 0; t < n; ++t) {
        double winner = tree[1];

        cout << "\nStep " << step
             << ": current winner is "
             << winner << endl;

        result.push_back(winner);

        int i = 1;
        while (i < offset) {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (tree[left] == winner)
                i = left;
            else
                i = right;
        }

        cout << "  Winner found at leaf index "
             << i
             << ", replacing with infinity" << endl;

        tree[i] = numeric_limits<double>::infinity();

        _update_tree(tree, i);

        cout << "  Tree after update:" << endl;
        cout << "  [ ";
        for (double x : tree) cout << x << " ";
        cout << "]" << endl;

        cout << "  Result so far: ";
        for (double x : result) cout << x << " ";
        cout << endl;

        step++;
    }

    cout << "\nSorted: ";
    for (double x : result) cout << x << " ";
    cout << endl;

    return result;
}


vector<double> tournament_sort(const vector<double>& arr) {
    vector<double> a = arr;
    int n = a.size();

    auto [tree, offset, size] = _build_tree(a);

    vector<double> result;

    for (int t = 0; t < n; ++t) {
        double winner = tree[1];
        result.push_back(winner);

        int i = 1;
        while (i < offset) {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (tree[left] == winner)
                i = left;
            else
                i = right;
        }

        tree[i] = numeric_limits<double>::infinity();
        _update_tree(tree, i);
    }

    return result;
}