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
