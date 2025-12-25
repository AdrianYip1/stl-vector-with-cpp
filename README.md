# C++ Customer Vector Class

This project implements a STL stye design of 'std::vector'

## Features

- Template based generic container
- Dynamic array resizing
- Meomry management with 'new[]' and 'delete[]'
- Rule of 5 (Constructor (copy/move), assignment, and destructor)
- STL style iterators with begin(), end(), rbegin(), and rend()
- Management of array capacity
- Equality and inequality operators

  ## Example implementation

  ```cpp
  Vector<int> test;
  test.push_back(1);
  test.push_back(3);

  for (int x : test) {
  std::cout << x << " ";
  }
