#include <iostream>
#include <memory>
#include <vector>

class Resource {
private:
  int id;

public:
  Resource(int id = 0) : id(id) {
    std::cout << "Resource Constructor Called (ID: " << id << ")" << std::endl;
  }
  ~Resource() {
    std::cout << "Resource Destructor Called (ID: " << id << ")" << std::endl;
  }
  void display() {
    std::cout << "Resource object with ID: " << id << std::endl;
  }
};

// Example 1: Basic shared_ptr creation
void example1_basic_creation() {
  std::cout << "\n=== Example 1: Basic Creation ===" << std::endl;

  // Using make_shared (preferred way)
  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(1);
  ptr1->display();
  std::cout << "Reference count: " << ptr1.use_count() << std::endl;

  // Direct creation with new
  std::shared_ptr<Resource> ptr2(new Resource(2));
  ptr2->display();
  std::cout << "Reference count: " << ptr2.use_count() << std::endl;

  std::cout << "Example 1 ends - objects will be destroyed\n" << std::endl;
}

// Example 2: Shared ownership (multiple pointers)
void example2_shared_ownership() {
  std::cout << "\n=== Example 2: Shared Ownership ===" << std::endl;

  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(10);
  Resource *ptr = new Resource(30);
  std::shared_ptr<Resource> _ptr(ptr);
  ptr1->display();
  std::cout << "Reference count after creation: " << ptr1.use_count()
            << std::endl;

  // Create another shared_ptr pointing to same object
  std::shared_ptr<Resource> ptr2 = ptr1;
  std::cout << "Reference count after copying ptr1 to ptr2: "
            << ptr1.use_count() << std::endl;

  // Create a third shared_ptr pointing to same object
  std::shared_ptr<Resource> ptr3 = ptr1;
  std::cout << "Reference count after copying ptr1 to ptr3: "
            << ptr1.use_count() << std::endl;

  std::cout << "All three pointers reference the same object" << std::endl;
  ptr2->display();
  ptr3->display();

  std::cout
      << "Example 2 ends - object destroyed when last ptr goes out of scope\n"
      << std::endl;
}

// Example 3: Reference counting
void example3_reference_counting() {
  std::cout << "\n=== Example 3: Reference Counting ===" << std::endl;

  {
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(20);
    std::cout << "Inside scope 1, count: " << ptr1.use_count() << std::endl;

    {
      std::shared_ptr<Resource> ptr2 = ptr1;
      std::cout << "Inside scope 2, count: " << ptr1.use_count() << std::endl;

      {
        std::shared_ptr<Resource> ptr3 = ptr1;
        std::cout << "Inside scope 3, count: " << ptr1.use_count() << std::endl;
      }

      std::cout << "After scope 3, count: " << ptr1.use_count() << std::endl;
    }

    std::cout << "After scope 2, count: " << ptr1.use_count() << std::endl;
  }

  std::cout << "After scope 1 - object destroyed\n" << std::endl;
}

// Example 4: shared_ptr with reset()
void example4_reset() {
  std::cout << "\n=== Example 4: Reset ===" << std::endl;

  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(30);
  std::shared_ptr<Resource> ptr2 = ptr1;

  std::cout << "Reference count: " << ptr1.use_count() << std::endl;

  std::cout << "Calling reset() on ptr1" << std::endl;
  ptr1.reset();

  std::cout << "After reset, ptr2 still valid with count: " << ptr2.use_count()
            << std::endl;
  ptr2->display();

  std::cout << "Example 4 ends\n" << std::endl;
}

// Example 5: shared_ptr in containers
void example5_shared_ptr_in_container() {
  std::cout << "\n=== Example 5: shared_ptr in Vector ===" << std::endl;

  std::vector<std::shared_ptr<Resource>> vec;

  // Create and add objects
  vec.push_back(std::make_shared<Resource>(40));
  vec.push_back(std::make_shared<Resource>(41));
  vec.push_back(std::make_shared<Resource>(42));

  // Get a shared_ptr to first object
  std::shared_ptr<Resource> ptr = vec[0];
  std::cout << "Reference count for first object: " << ptr.use_count()
            << std::endl;

  std::cout << "Displaying all objects in vector:" << std::endl;
  for (auto &sp : vec) {
    sp->display();
  }

  std::cout << "Example 5 ends\n" << std::endl;
}

// Example 6: Using get() to access raw pointer
void example6_get_raw_pointer() {
  std::cout << "\n=== Example 6: Using get() ===" << std::endl;

  std::shared_ptr<Resource> ptr = std::make_shared<Resource>(50);

  // Get raw pointer without affecting reference count
  Resource *raw_ptr = ptr.get();
  raw_ptr->display();

  std::cout << "Reference count still: " << ptr.use_count() << std::endl;
  std::cout << "Example 6 ends - object will be destroyed\n" << std::endl;
}

// Example 7: Function taking shared_ptr by value
void process_resource(std::shared_ptr<Resource> ptr) {
  std::cout << "Processing resource in function" << std::endl;
  std::cout << "Reference count in function: " << ptr.use_count() << std::endl;
  ptr->display();
  // Reference count decreases when function ends
}

void example7_function_parameter() {
  std::cout << "\n=== Example 7: Passing shared_ptr to Function ==="
            << std::endl;

  std::shared_ptr<Resource> ptr = std::make_shared<Resource>(60);
  std::cout << "Before function call, count: " << ptr.use_count() << std::endl;

  process_resource(ptr);

  std::cout << "After function call, count: " << ptr.use_count() << std::endl;
  std::cout << "Example 7 ends\n" << std::endl;
}

// Example 8: Function returning shared_ptr
std::shared_ptr<Resource> create_resource(int id) {
  std::cout << "Creating resource in function" << std::endl;
  return std::make_shared<Resource>(id);
}

void example8_function_return() {
  std::cout << "\n=== Example 8: Function Returning shared_ptr ==="
            << std::endl;

  auto ptr1 = create_resource(70);
  std::cout << "Reference count after first creation: " << ptr1.use_count()
            << std::endl;

  auto ptr2 = create_resource(71);
  std::cout << "Reference count of ptr1: " << ptr1.use_count() << std::endl;
  std::cout << "Reference count of ptr2: " << ptr2.use_count() << std::endl;

  std::cout << "Example 8 ends\n" << std::endl;
}

// Example 9: Comparison with unique_ptr behavior
void example9_comparison_unique_vs_shared() {
  std::cout << "\n=== Example 9: Difference from unique_ptr ===" << std::endl;

  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(80);
  std::cout << "Created ptr1, count: " << ptr1.use_count() << std::endl;

  // With shared_ptr, copying is safe and increases reference count
  std::shared_ptr<Resource> ptr2 = ptr1;
  std::cout << "Copied to ptr2, count: " << ptr1.use_count() << std::endl;

  // Both can be used independently
  ptr1->display();
  ptr2->display();

  // Object exists as long as at least one pointer holds it
  ptr1.reset();
  std::cout << "After ptr1.reset(), count: " << ptr2.use_count() << std::endl;
  std::cout << "ptr2 still valid: ";
  ptr2->display();

  std::cout << "Example 9 ends\n" << std::endl;
}

// Example 10: Aliasing constructor
void example10_aliasing() {
  std::cout << "\n=== Example 10: Aliasing Constructor ===" << std::endl;

  std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>(90);
  std::cout << "Original ptr1 count: " << ptr1.use_count() << std::endl;

  // Create another shared_ptr that shares ownership with ptr1
  // but points to a different address (not common, but possible)
  std::shared_ptr<int> ptr2(ptr1, (int *)nullptr);

  std::cout << "After aliasing, ptr1 count: " << ptr1.use_count() << std::endl;
  std::cout << "ptr2 count: " << ptr2.use_count() << std::endl;

  std::cout << "Example 10 ends\n" << std::endl;
}

int main() {

  std::cout << "========== Shared Pointer Examples ==========" << std::endl;

  example1_basic_creation();
  example2_shared_ownership();
  example3_reference_counting();
  example4_reset();
  example5_shared_ptr_in_container();
  example6_get_raw_pointer();
  example7_function_parameter();
  example8_function_return();
  example9_comparison_unique_vs_shared();
  example10_aliasing();

  std::cout << "========== End of main function ==========" << std::endl;
  return 0;
}
