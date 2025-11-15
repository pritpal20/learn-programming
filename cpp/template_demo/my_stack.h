#include "my_vector.h"
#include <iostream>

template <typename T> class MyStack {
private:
  MyVector<T> data;
  std::size_t topIndex;

public:
  MyStack() : topIndex(-1) {}

  void push(const T &value) {
    data.push_back(value);
    topIndex++;
  }

  void pop() {
    if (!is_empty()) {
      data.pop_back();
      topIndex--;
    }
  }

  // T& top() {
  //     if (!is_empty()) {
  //         return data[topIndex];
  //     throw std::out_of_range("Stack is empty");
  // }

  bool is_empty() { return topIndex == -1; }

  // std::size_t size() const {
  //     return topIndex + 1;
  // }
};
