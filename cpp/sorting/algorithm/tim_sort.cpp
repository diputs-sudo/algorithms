/*
TimSort Algorithm

TimSort is a hybrid sorting algorithm used in Python, Java, and many
other programming languages.

It combines ideas from insertion sort and merge sort.

How it works:
- The array is divided into small sections called runs.
- Each run is sorted using insertion sort.
- The sorted runs are merged together.
- Runs are merged repeatedly until the entire array is sorted.

This approach performs very well on real world data because
many datasets already contain partially sorted sequences.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n) when the data is nearly sorted.

Space Complexity:
- O(n) due to merging operations.

Stability:
- Stable because merging preserves order of equal elements.

Note:
This is a simplified educational version.
The industrial implementation used in Python includes
additional optimizations such as natural run detection,
stack invariants, and galloping mode.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Assume insertion_sort and insertion_sort_verbose exist
vector<int> insertion_sort(const vector<int>& arr);
vector<int> insertion_sort_verbose(const vector<int>& arr);

const int MIN_RUN = 5;


pair<vector<int>, int> _merge_verbose(
    const vector<int>& left,
    const vector<int>& right,
    int step_start = 1
) {
    vector<int> result;
    int i = 0, j = 0;
    int step = step_start;

    cout << "  Merging ";
    for (int x : left) cout << x << " ";
    cout << "and ";
    for (int x : right) cout << x << " ";
    cout << endl;

    while (i < left.size() && j < right.size()) {
        cout << "  Step " << step << ": compare "
             << left[i] << " and " << right[j] << endl;

        if (left[i] <= right[j]) {
            cout << "    take " << left[i] << " from left" << endl;
            result.push_back(left[i]);
            i++;
        } else {
            cout << "    take " << right[j] << " from right" << endl;
            result.push_back(right[j]);
            j++;
        }

        cout << "    result so far: ";
        for (int x : result) cout << x << " ";
        cout << endl;

        step++;
    }

    if (i < left.size()) {
        cout << "  Append remaining from left: ";
        for (int k = i; k < left.size(); ++k) cout << left[k] << " ";
        cout << endl;
    }

    if (j < right.size()) {
        cout << "  Append remaining from right: ";
        for (int k = j; k < right.size(); ++k) cout << right[k] << " ";
        cout << endl;
    }

    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());

    cout << "  Merged result: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return {result, step};
}


vector<int> tim_sort_verbose(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    cout << "Start: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "MIN_RUN = " << MIN_RUN << endl;

    cout << "\n=== Phase 1: Sort runs with insertion sort ===" << endl;

    for (int start = 0; start < n; start += MIN_RUN) {
        int end = min(start + MIN_RUN, n);

        cout << "\nRun from index "
             << start << " to "
             << end - 1 << ": ";

        for (int i = start; i < end; ++i) cout << a[i] << " ";
        cout << endl;

        vector<int> run(a.begin() + start, a.begin() + end);
        vector<int> sorted_run = insertion_sort_verbose(run);

        copy(sorted_run.begin(), sorted_run.end(), a.begin() + start);

        cout << "Array after sorting this run: ";
        for (int x : a) cout << x << " ";
        cout << endl;
    }

    cout << "\n=== Phase 2: Merge runs ===" << endl;

    int size = MIN_RUN;
    int step = 1;

    while (size < n) {
        cout << "\n--- Merge size = " << size << " ---" << endl;

        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size, n);
            int right = min(left + 2 * size, n);

            vector<int> left_part(a.begin() + left, a.begin() + mid);
            vector<int> right_part(a.begin() + mid, a.begin() + right);

            cout << "\nMerging slices a["
                 << left << ":" << mid << "] and a["
                 << mid << ":" << right << "]" << endl;

            auto merged_pair =
                _merge_verbose(left_part, right_part, step);

            vector<int> merged = merged_pair.first;
            step = merged_pair.second;

            copy(merged.begin(), merged.end(), a.begin() + left);

            cout << "Array after merge: ";
            for (int x : a) cout << x << " ";
            cout << endl;
        }

        size *= 2;
    }

    cout << "\nSorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return a;
}


vector<int> _merge(
    const vector<int>& left,
    const vector<int>& right
) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());

    return result;
}


vector<int> tim_sort(const vector<int>& arr) {
    vector<int> a = arr;
    int n = a.size();

    for (int start = 0; start < n; start += MIN_RUN) {
        int end = min(start + MIN_RUN, n);

        vector<int> run(a.begin() + start, a.begin() + end);
        vector<int> sorted_run = insertion_sort(run);

        copy(sorted_run.begin(), sorted_run.end(), a.begin() + start);
    }

    int size = MIN_RUN;

    while (size < n) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size, n);
            int right = min(left + 2 * size, n);

            vector<int> left_part(a.begin() + left, a.begin() + mid);
            vector<int> right_part(a.begin() + mid, a.begin() + right);

            vector<int> merged = _merge(left_part, right_part);

            copy(merged.begin(), merged.end(), a.begin() + left);
        }

        size *= 2;
    }

    return a;
}