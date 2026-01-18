#include <iostream>
#include <memory>
#include <vector>

class Demo {
private:
  int id;

public:
  Demo(int id = 0) : id(id) {
    std::cout << "Demo Constructor Called (ID: " << id << ")" << std::endl;
  }
  ~Demo() {
    std::cout << "Demo Destructor Called (ID: " << id << ")" << std::endl;
  }
  void display() { std::cout << "Demo object with ID: " << id << std::endl; }
};

// Example 1: Basic unique_ptr creation and usage
void example1_basic_creation() {
  std::cout << "\n=== Example 1: Basic Creation ===" << std::endl;

  // Using make_unique (preferred way)
  std::unique_ptr<Demo> ptr1 = std::make_unique<Demo>(1);
  ptr1->display();

  // Direct creation with new
  std::unique_ptr<Demo> ptr2(new Demo(2));
  ptr2->display();

  std::cout << "Example 1 ends - objects will be destroyed\n" << std::endl;
}

// Example 2: Moving ownership
void example2_move_semantics() {
  std::cout << "\n=== Example 2: Move Semantics ===" << std::endl;

  std::unique_ptr<Demo> ptr1 = std::make_unique<Demo>(10);
  ptr1->display();

  // Transfer ownership from ptr1 to ptr2
  std::unique_ptr<Demo> ptr2 = std::move(ptr1);

  // ptr1 is now null, ptr2 owns the object
  if (ptr1 == nullptr) {
    std::cout << "ptr1 is now null after move" << std::endl;
  }

  ptr2->display();
  std::cout << "Example 2 ends - object will be destroyed\n" << std::endl;
}

// Example 3: Manual memory release
void example3_reset() {
  std::cout << "\n=== Example 3: Manual Reset ===" << std::endl;

  std::unique_ptr<Demo> ptr3 = std::make_unique<Demo>(20);
  ptr3->display();

  std::cout << "Calling reset() to manually delete the object" << std::endl;
  ptr3.reset(); // Manually delete the memory managed by ptr3

  if (ptr3 == nullptr) {
    std::cout << "ptr3 is now null after reset" << std::endl;
  }
  std::cout << "Example 3 ends\n" << std::endl;
}

// Example 4: Using unique_ptr with arrays
void example4_array_unique_ptr() {
  std::cout << "\n=== Example 4: Array unique_ptr ===" << std::endl;

  // Array of 3 Demo objects
  std::unique_ptr<Demo[]> arr = std::make_unique<Demo[]>(3);
  arr[0].display();
  arr[1].display();
  arr[2].display();

  std::cout << "Example 4 ends - all objects will be destroyed\n" << std::endl;
}

// Example 5: unique_ptr in containers
void example5_unique_ptr_in_container() {
  std::cout << "\n=== Example 5: unique_ptr in Vector ===" << std::endl;

  // Vector of unique pointers
  std::vector<std::unique_ptr<Demo>> vec;

  // Add objects to vector
  vec.push_back(std::make_unique<Demo>(30));
  vec.push_back(std::make_unique<Demo>(31));
  vec.push_back(std::make_unique<Demo>(32));

  std::cout << "Displaying all objects in vector:" << std::endl;
  for (auto &ptr : vec) {
    ptr->display();
  }

  std::cout << "Example 5 ends - all objects in vector will be destroyed\n"
            << std::endl;
}

// Example 6: Using get() to access raw pointer
void example6_get_raw_pointer() {
  std::cout << "\n=== Example 6: Using get() ===" << std::endl;

  std::unique_ptr<Demo> ptr = std::make_unique<Demo>(40);

  // Get raw pointer without transferring ownership
  Demo *raw_ptr = ptr.get();
  raw_ptr->display();

  ptr.reset(); // Clean up the unique_ptr

  if (raw_ptr) {
    std::cout << "Raw pointer after unique_ptr reset: ";

    raw_ptr->display(); // Undefined behavior after unique_ptr reset
  }

  std::cout << "Raw pointer is valid as long as unique_ptr exists" << std::endl;
  std::cout << "Example 6 ends - object will be destroyed\n" << std::endl;
}

// Example 7: Using release() to release ownership
void example7_release() {
  std::cout << "\n=== Example 7: Using release() ===" << std::endl;

  std::unique_ptr<Demo> ptr = std::make_unique<Demo>(50);
  ptr->display();

  // Release ownership and get raw pointer
  Demo *raw_ptr = ptr.release();
  std::cout << "Ownership released from unique_ptr" << std::endl;

  if (ptr == nullptr) {
    std::cout << "unique_ptr is now null after release" << std::endl;
  }

  raw_ptr->display();
  std::cout << "Note: Manual cleanup needed for released object" << std::endl;
  delete raw_ptr; // Manual cleanup required
  std::cout << "Example 7 ends\n" << std::endl;
}

// Example 8: Function taking unique_ptr as parameter
void process_demo(std::unique_ptr<Demo> ptr) {
  std::cout << "Processing object in function:" << std::endl;
  ptr->display();
  // Ownership is transferred to this function
  // Object will be deleted when function ends
}

void example8_function_parameter() {
  std::cout << "\n=== Example 8: Passing unique_ptr to Function ==="
            << std::endl;

  std::unique_ptr<Demo> ptr = std::make_unique<Demo>(60);

  // Transfer ownership to function
  process_demo(std::move(ptr));

  if (ptr == nullptr) {
    std::cout << "ptr is null after function call (ownership transferred)"
              << std::endl;
  }
  std::cout << "Example 8 ends\n" << std::endl;
}

// Example 9: Function returning unique_ptr
std::unique_ptr<Demo> create_demo(int id) {
  std::cout << "Creating demo object in function" << std::endl;
  return std::make_unique<Demo>(id);
}

void example9_function_return() {
  std::cout << "\n=== Example 9: Function Returning unique_ptr ==="
            << std::endl;

  auto ptr = create_demo(70);
  ptr->display();

  std::cout << "Example 9 ends - object will be destroyed\n" << std::endl;
}

int main() {

  std::cout << "========== Unique Pointer Examples ==========" << std::endl;

  example1_basic_creation();
  example2_move_semantics();
  example3_reset();
  example4_array_unique_ptr();
  example5_unique_ptr_in_container();
  example6_get_raw_pointer();
  example7_release();
  example8_function_parameter();
  example9_function_return();

  std::cout << "========== End of main function ==========" << std::endl;
  return 0;
}