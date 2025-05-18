#include <unordered_set>

using namespace std;

char find_first_duplicate_char(const std::string& str) {
    std::unordered_set<char> seen;
    for (char c : str) {
        if (seen.count(c)) {
            return c; // Return the first duplicate character found
        }
        seen.insert(c);
    }
    return '\0'; // Return null character if no duplicates are found
}


int merge_sort_alorithm()
{
    // Merge sort algorithm implementation
    // This is a placeholder for the actual implementation
    return 0;
}
