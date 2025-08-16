#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class MyVector {
public:
  MyVector() {
    capacity = 5;
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

  // Returns true if the vector is empty, false otherwise.
  // This function checks if the size of the vector is zero.
  bool empty() const { return m_size == 0; }
  // Returns the current capacity of the vector.
  std::size_t get_capacity() const { return capacity; }

private:
  T *data;
  std::size_t capacity; // initial capacity
  size_t m_size;
};

int main() {
  MyVector<int> intVector;
  intVector.push_back(1);
  intVector.push_back(2);
  intVector.push_back(3);
  intVector.push_back(4);
  intVector.push_back(5);
  intVector.push_back(6);
  intVector.push_back(7);
  intVector.push_back(8);
  intVector.push_back(9);
  intVector.push_back(10);
  intVector.push_back(11);

  MyVector<int> intVector2 = intVector;
  std::cout << intVector2 << std::endl;

  return 0;
}
