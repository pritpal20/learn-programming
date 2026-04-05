#include <iostream>
#include <memory>

int main() {
  // Create a shared_ptr
  std::shared_ptr<int> sp = std::make_shared<int>(42);
  std::cout << "Shared pointer created with value: " << *sp << std::endl;

  // Create a weak_ptr from shared_ptr
  std::weak_ptr<int> wp = sp;
  std::cout << "Weak pointer created from shared_ptr." << std::endl;

  // Check if weak_ptr is expired and lock it
  if (auto locked = wp.lock()) {
    std::cout << "Weak pointer locked, value: " << *locked << std::endl;
  } else {
    std::cout << "Weak pointer is expired." << std::endl;
  }

  // Reset shared_ptr, making weak_ptr expire
  sp.reset();
  std::cout << "Shared pointer reset." << std::endl;

  // Try to lock weak_ptr again
  if (auto locked = wp.lock()) {
    std::cout << "Weak pointer locked, value: " << *locked << std::endl;
  } else {
    std::cout << "Weak pointer is expired." << std::endl;
  }

  return 0;
}