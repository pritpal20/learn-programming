#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class MyVector {
public:
  MyVector() {
    capacity = 1;
    m_size = 0;
    data = new T[capacity];
  }

  // Copy constructor: Performs a deep copy of the `MyVector` object.
  // It allocates new memory for the `data` array and copies each element from
  // the source object.
  MyVector(const MyVector &other) {
    m_size = other.m_size;
    capacity = other.capacity;
    data = new T[other.capacity];

    for (size_t i = 0; i < other.size(); i++) {
      data[i] = other.data[i];
    }
  }

  ~MyVector() { delete[] data; }

  void push_back(const T &value) {
    data[m_size] = value;
    ++m_size;

    if (m_size == capacity) {
      // Resize the underlying vector if capacity is reached
      capacity = (capacity == 0) ? 1 : capacity * 2;
      std::cout << "size " << m_size << " capacity " << capacity << std::endl;
      resize(capacity);
    }
  }

  void resize(std::size_t capcity) {
    T *newData = new T[capcity];
    for (std::size_t i = 0; i < size(); ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }

  T &operator[](std::size_t index) { return data[index]; }

  friend std::ostream &operator<<(std::ostream &out, MyVector &other) {
    for (int i = 0; i < other.size(); i++)
      out << other[i] << ",";

    return out;
  }

  std::size_t size() const { return m_size; }

  bool empty() const { return m_size == 0; }

  std::size_t get_capacity() const { return capacity; }

private:
  T *data;
  std::size_t capacity; // initial capacity
  size_t m_size;
};
