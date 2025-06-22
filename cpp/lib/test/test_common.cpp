#include "cpp/lib/common.h"
#include <gtest/gtest.h>

// Assuming find_first_duplicate_char is defined in lib/common.h
// and it takes a const std::string& as input and returns a char.

TEST(FindFirstDuplicateCharTest, NoDuplicates) {
    std::string input = "abcdef";
    char result = find_first_duplicate_char(input);
    EXPECT_EQ(result, '\0'); // Assuming '\0' is returned for no duplicates.
}

TEST(FindFirstDuplicateCharTest, SingleDuplicate) {
    std::string input = "abcdea";
    char result = find_first_duplicate_char(input);
    EXPECT_EQ(result, 'a');
}

TEST(FindFirstDuplicateCharTest, MultipleDuplicates) {
    std::string input = "abcbade";
    char result = find_first_duplicate_char(input);
    EXPECT_EQ(result, 'b'); // Assuming the first duplicate is returned.
}

TEST(FindFirstDuplicateCharTest, EmptyString) {
    std::string input = "";
    char result = find_first_duplicate_char(input);
    EXPECT_EQ(result, '\0'); // Assuming '\0' is returned for empty input.
}

TEST(FindFirstDuplicateCharTest, SingleCharacter) {
    std::string input = "a";
    char result = find_first_duplicate_char(input);
    EXPECT_EQ(result, '\0'); // No duplicates in a single character string.
}
// Tests for bubble_sort function
// Assuming bubble_sort is defined in lib/common.h
// and it takes a std::vector<int>& as input and sorts it in place.

TEST(BubbleSortTest, AlreadySorted) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, ReverseOrder) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, RandomOrder) {
    std::vector<int> input = {3, 1, 4, 5, 2};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, WithDuplicates) {
    std::vector<int> input = {4, 2, 2, 3, 1};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 2, 3, 4}));
}

TEST(BubbleSortTest, SingleElement) {
    std::vector<int> input = {42};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{42}));
}

TEST(BubbleSortTest, EmptyVector) {
    std::vector<int> input = {};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{}));
}

TEST(BubbleSortTest, AllEqualElements) {
    std::vector<int> input = {7, 7, 7, 7};
    bubble_sort(input);
    EXPECT_EQ(input, (std::vector<int>{7, 7, 7, 7}));
}
TEST(SelectionSortTest, AlreadySorted) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, ReverseOrder) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, RandomOrder) {
    std::vector<int> input = {3, 1, 4, 5, 2};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, WithDuplicates) {
    std::vector<int> input = {4, 2, 2, 3, 1};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{1, 2, 2, 3, 4}));
}

TEST(SelectionSortTest, SingleElement) {
    std::vector<int> input = {42};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{42}));
}

TEST(SelectionSortTest, EmptyVector) {
    std::vector<int> input = {};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{}));
}

TEST(SelectionSortTest, AllEqualElements) {
    std::vector<int> input = {7, 7, 7, 7};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<int>{7, 7, 7, 7}));
}
//selection sort for float value 
TEST(SelectionSortTest, FloatValues) {
    std::vector<float> input = {3.2f, 1.5f, 4.8f, 2.1f, 2.1f};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<float>{1.5f, 2.1f, 2.1f, 3.2f, 4.8f}));
}

TEST(SelectionSortTest, NegativeAndPositiveFloats) {
    std::vector<float> input = {-2.5f, 3.1f, 0.0f, -1.1f, 2.2f};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<float>{-2.5f, -1.1f, 0.0f, 2.2f, 3.1f}));
}

TEST(SelectionSortTest, AllEqualFloats) {
    std::vector<float> input = {2.2f, 2.2f, 2.2f};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<float>{2.2f, 2.2f, 2.2f}));
}

TEST(SelectionSortTest, SingleFloatElement) {
    std::vector<float> input = {5.5f};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<float>{5.5f}));
}

TEST(SelectionSortTest, EmptyFloatVector) {
    std::vector<float> input = {};
    selection_sort(input);
    EXPECT_EQ(input, (std::vector<float>{}));
}
