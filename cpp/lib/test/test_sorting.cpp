#include "cpp/lib/common.h" // Assuming common.h contains necessary includes and declarations
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

// Assume quick_sort is defined as:
// void quick_sort(std::vector<int>& arr);

// void quick_sort(std::vector<int>& arr); // Forward declaration

TEST(QuickSortTest, SortsEmptyVector) {
  std::vector<int> arr;
  quick_sort(arr);
  EXPECT_TRUE(arr.empty());
}

TEST(QuickSortTest, SortsSingleElement) {
  std::vector<int> arr = {42};
  quick_sort(arr);
  EXPECT_EQ(arr, std::vector<int>({42}));
}

TEST(QuickSortTest, SortsAlreadySorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  quick_sort(arr);
  EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, SortsReverseSorted) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  quick_sort(arr);
  EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, SortsWithDuplicates) {
  std::vector<int> arr = {3, 1, 2, 3, 2, 1};
  quick_sort(arr);
  EXPECT_EQ(arr, std::vector<int>({1, 1, 2, 2, 3, 3}));
}

TEST(QuickSortTest, SortsNegativeNumbers) {
  std::vector<int> arr = {-3, -1, -2, 0, 2, 1};
  quick_sort(arr);
  EXPECT_EQ(arr, std::vector<int>({-3, -2, -1, 0, 1, 2}));
}

TEST(QuickSortTest, SortsLargeVector) {
  std::vector<int> arr(1000);
  for (int i = 0; i < 1000; ++i)
    arr[i] = 1000 - i;
  quick_sort(arr);
  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(arr[i], i + 1);
  }
}