/*
IntroSort Algorithm

IntroSort is a hybrid sorting algorithm that combines
Quick Sort, Heap Sort, and Insertion Sort.

How it works:
- It begins with Quick Sort.
- If recursion depth becomes too large, it switches to Heap Sort.
- For small subarrays, it uses Insertion Sort.
- This combination guarantees both speed and worst case safety.

The depth limit is typically set to 2 x log2(n).
If that depth is exceeded, Heap Sort is used to avoid
Quick Sort worst case behavior.

Time Complexity:
- Worst Case: O(n log n)
- Average Case: O(n log n)
- Best Case: O(n log n)

Space Complexity:
- O(n) in this implementation due to extra lists.

Stability:
- Not stable.

Note:
IntroSort is used in many standard library implementations
because it provides fast average performance while also
guaranteeing O(n log n) worst case time.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Assume these are defined elsewhere in your project
vector<int> heap_sort(const vector<int>& arr);
vector<int> insertion_sort(const vector<int>& arr);


vector<int> _intro_sort_verbose(vector<int> a, int max_depth, int depth);


vector<int> intro_sort_verbose(const vector<int>& arr) {
    cout << "Start: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int max_depth = 2 * (int)log2(arr.size() > 0 ? arr.size() : 1);

    vector<int> result = _intro_sort_verbose(arr, max_depth, 0);

    cout << "\nSorted: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return result;
}


vector<int> _intro_sort_verbose(vector<int> a, int max_depth, int depth) {
    string indent(depth * 2, ' ');

    cout << indent << "IntroSort(";
    for (int x : a) cout << x << " ";
    cout << "), max_depth=" << max_depth << endl;

    if (a.size() <= 16) {
        cout << indent << "Use insertion sort for small array" << endl;
        return insertion_sort(a);
    }

    if (max_depth == 0) {
        cout << indent << "Depth limit reached, switch to heap sort" << endl;
        return heap_sort(a);
    }

    int pivot = a[a.size() / 2];

    vector<int> left;
    vector<int> middle;
    vector<int> right;

    for (int x : a) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }

    vector<int> result;

    vector<int> left_sorted =
        _intro_sort_verbose(left, max_depth - 1, depth + 1);

    vector<int> right_sorted =
        _intro_sort_verbose(right, max_depth - 1, depth + 1);

    result.insert(result.end(), left_sorted.begin(), left_sorted.end());
    result.insert(result.end(), middle.begin(), middle.end());
    result.insert(result.end(), right_sorted.begin(), right_sorted.end());

    return result;
}


vector<int> _intro_sort(vector<int> a, int max_depth) {
    if (a.size() <= 16) {
        return insertion_sort(a);
    }

    if (max_depth == 0) {
        return heap_sort(a);
    }

    int pivot = a[a.size() / 2];

    vector<int> left;
    vector<int> middle;
    vector<int> right;

    for (int x : a) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }

    vector<int> result;

    vector<int> left_sorted =
        _intro_sort(left, max_depth - 1);

    vector<int> right_sorted =
        _intro_sort(right, max_depth - 1);

    result.insert(result.end(), left_sorted.begin(), left_sorted.end());
    result.insert(result.end(), middle.begin(), middle.end());
    result.insert(result.end(), right_sorted.begin(), right_sorted.end());

    return result;
}


vector<int> intro_sort(const vector<int>& arr) {
    int max_depth = 2 * (int)log2(arr.size() > 0 ? arr.size() : 1);
    return _intro_sort(arr, max_depth);
}