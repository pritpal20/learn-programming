#include <demo.h>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Hello, World!" << std::endl;

  // Test demo.h functions
  std::cout << "Add: " << add(5, 3) << std::endl;
  std::cout << "Subtract: " << subtract(5, 3) << std::endl;
  std::cout << "Multiply: " << multiply(5, 3) << std::endl;
  std::cout << "Square: " << square(5) << std::endl;

  return 0;
}
