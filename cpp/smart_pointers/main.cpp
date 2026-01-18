// This code demonstrates the use of smart pointers in C++.
// It includes examples of both unique_ptr and shared_ptr, showcasing their
// memory management capabilities.

#include <iostream>
#include <memory>

class Demo {
public:
  Demo() { std::cout << "Demo Constructor Called" << std::endl; }
  ~Demo() { std::cout << "Demo Destructor Called" << std::endl; }
};

void uniquePointerExample() {
  // Create a unique_ptr
  std::unique_ptr<int> ptr = std::make_unique<int>(10);
  std::cout << "Value: " << *ptr << std::endl;
  std::cout << "Unique pointer is managing the memory." << ptr.get()
            << std::endl;

  std::unique_ptr<int> ptr2 = std::move(ptr);
  std::cout << "Unique pointer is managing the memory." << ptr2.get()
            << std::endl;
  std::cout << "Original pointer is now null: " << (ptr == nullptr)
            << std::endl;
  // Note: The memory will be automatically freed when ptr goes out of scope.
}

void UniquePointerDeleteExample() {
  // Create a unique_ptr
  std::unique_ptr<Demo> ptr = std::make_unique<Demo>();
  // std::cout << "Value: " << *ptr << std::endl;
  std::cout << "Unique pointer is managing the memory." << ptr.get()
            << std::endl;
  // Manually delete the memory
  ptr.reset(); // This will delete the memory managed by ptr
  std::cout << "Memory manually deleted." << std::endl;
  std::cout << "Unique pointer is now null: " << (ptr == nullptr) << std::endl;
}

void sharedPointerExample() {
  // Create a shared_ptr
  std::shared_ptr<int> ptr = std::make_shared<int>(20);
  std::cout << "Value: " << *ptr << std::endl;
  std::cout << "Shared pointer is managing the memory." << ptr.get()
            << std::endl;

  {
    std::shared_ptr<int> ptr2 = ptr; // Shared ownership
    std::cout << "Shared pointer count: " << ptr.use_count() << std::endl;
    std::cout << "Shared pointer is managing the memory." << ptr2.get()
              << std::endl;
  } // ptr2 goes out of scope, but memory is not freed yet.

  std::cout << "Shared pointer count after ptr2 goes out of scope: "
            << ptr.use_count() << std::endl;
  // Note: The memory will be automatically freed when the last shared_ptr goes
  // out of scope.
}

int main(int argc, char const *argv[]) {
  // Create a unique_ptr

  if (argc < 2) {
    std::cout << "Usage: " << "./main" << " <unique/shared>" << std::endl;
    return 1;
  }

  if (std::string(argv[1]) == "unique") {
    uniquePointerExample();
    UniquePointerDeleteExample();
  } else if (std::string(argv[1]) == "shared") {
    sharedPointerExample();
  } else {
    std::cout << "Invalid argument. Please use 'unique' or 'shared'."
              << std::endl;
    return 1;
  }

  return 0;
}
