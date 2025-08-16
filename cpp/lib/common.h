#include <unordered_set>

using namespace std;

char find_first_duplicate_char(const std::string &str) {
  std::unordered_set<char> seen;
  for (char c : str) {
    if (seen.count(c)) {
      return c; // Return the first duplicate character found
    }
    seen.insert(c);
  }
  return '\0'; // Return null character if no duplicates are found
}

int merge_sort_alorithm() {
  // Merge sort algorithm implementation
  // This is a placeholder for the actual implementation
  return 0;
}

void bubble_sort2(std::vector<int> &arr) {

  bool swapped;
  int n = arr.size();
  do {
    swapped = false;
    for (int i = 1; i < n; ++i) {
      if (arr[i - 1] > arr[i]) {
        std::swap(arr[i - 1], arr[i]);
        swapped = true;
      }
    }
    --n;
  } while (swapped);
}

void bubble_sort(std::vector<int> &arr) {

  bool swapped = true;
  int n = arr.size();
  while (swapped) {
    swapped = false;
    for (int i = 1; i < n; ++i) {
      if (arr[i - 1] > arr[i]) {
        std::swap(arr[i - 1], arr[i]);
        swapped = true;
      }
    }
    n--;
  }
}

// Selection sort algorithm
// Time Complexity: O(n^2), which is inefficient for large datasets.
// Consider using a more efficient algorithm like quicksort or mergesort for
// larger inputs. This algorithm repeatedly selects the smallest element from
// the unsorted portion of the vector and swaps it with the first unsorted
// element.
template <typename T> void selection_sort(std::vector<T> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      std::swap(arr[i], arr[min_idx]);
    }
  }
}

// Quick sort algorithm
template <typename T>
void quick_sort(std::vector<T> &arr, int left, int right) {
  if (left >= right)
    return;
  int pivot_idx = left + (right - left) / 2;
  T pivot = arr[pivot_idx];
  int i = left, j = right;
  while (i <= j) {
    while (arr[i] < pivot)
      ++i;
    while (arr[j] > pivot)
      --j;
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      ++i;
      --j;
    }
  }
  if (left < j)
    quick_sort(arr, left, j);
  if (i < right)
    quick_sort(arr, i, right);
}

// Helper function to call quick_sort easily
template <typename T> void quick_sort(std::vector<T> &arr) {
  if (!arr.empty())
    quick_sort(arr, 0, arr.size() - 1);
}