#include <iostream>

template <typename T> T max_element(const T &a, const T &b) {
  // This function returns the maximum element.
  return a > b ? a : b;
}

template <typename T, typename U> T max_element(const T &a, const U &b) {
  // This function returns the maximum element.
  return a > b ? a : b;
}

int main() {
  int x = 10, y = 20;
  double a = 5.0, b = 5;

  // Using the template function to find the maximum of integers
  int maxInt = max_element(x, y);
  std::cout << "Maximum of integers: " << maxInt << std::endl;
  // Using the template function to find the maximum of doubles
  double maxDouble = max_element(a, b);
  std::cout << "Maximum of doubles: " << maxDouble << std::endl;

  return 0;
}
