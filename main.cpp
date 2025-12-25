#include <iostream>
#include <cstring>
#include <stdexcept>
template <typename T>

class Vector {

    private:

        T* data;
        int _size;
        int _capacity;

    public:

        Vector() : _size(0), _capacity(2) {
            data = new T[_capacity];
        } //default constructor

        Vector(const Vector& rhs) : _size(rhs._size), _capacity(rhs._capacity) {
            data = new T[rhs._capacity];
            for (int i = 0; i < rhs._size; i++) {
                data[i] = rhs.data[i];
            }
        } //copy constructor

        Vector(Vector&& rhs) {
            data = rhs.data;
            _capacity = rhs._capacity
            _size = rhs._size;
            rhs.data = nullptr;
            rhs._capacity = 0;
            rhs._size = 0;
        } //move constructor


        void push_back(const T& x) {
            if (_size == _capacity) {
                _capacity *= 2;
                T* newData = new T[_capacity];
                for (int i = 0; i < _capacity/2;i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
            }
            data[_size++] = x;
        }     // add element to end

        void pop_back() {
            if (_size == 0) return;
            _size--;
        }       // remove last element

        int& operator[](const int i) {
            if (i < 0 || i >= _size) {
                throw out_of_range("Index out of bounds");
            };
            return data[i];
        }   // access element at index

        const int& at(int i) const {
            if (i < 0 || i >= _size) {
                throw out_of_range("Index out of bounds");
            };
            return data[i];
        }   // access element at index

        int size() const {
            return _size;
        }          // number of elements

        int capacity() const {
            return _capacity;
        }       // allocated space

        bool empty() const {
            return (_size==0);
        }          // check if empty

        void clear() {
            _size = 0;
        }  //clears vector

        int back() {
            if (_size == 0) {
                throw out_of_range("Vector has no entries");
            }
            return data[_size - 1];
        } //returns most recent entry

        int front() {
            if (_size > 0) {
                return data[0];
            }
            else {
                throw out_of_range("Vector has no entries");
            }
        } // returns first entry
        
        void reserve(int n) {
            if (n <= _capacity) {
                return;
            }
            
            T* newData = new T[n];
            for (int i = 0; i < _size; i++) {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;

        } //allocates an array of _size n

        void resize(int n) {
            if (n == _capacity) return;

            T* newData = new T[n];
            if (n > _size) {
                for (int i = 0; i < _size; i++) {
                    newData[i] = data[i];
                }
            }
            else {
                for (int i = 0; i < n; i++) {
                    newData[i] = data[i];
                }
            }

            delete[] data;
            data = newData;
        }

        void shrinkToFit() {
            if (_size < _capacity) {
                T* newData = new T[_size];
                for (int i = 0; i < _size; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
                _capacity = _size;
            }
        }

        void insert(int position, int value) {
            if (position < 0 || position > _size) {
                throw out_of_range("Invalid insert position");
            }
            if (_size == _capacity) {
                reserve(_capacity * 2);
            }
            for (int i = _size; i > position; i--)  {
                data[i] = data[i-1];
            }

            data[position] = value;
            _size++;
        }

        void erase(int position) {
            if (position < 0 || position >= _size) {
                throw out_of_range("Invalid erase position");
            }
            for (int i = position; i < _size - 1; i++) {
                data[i] = data[i+1];
            }
            _size--;
        }

        void eraseSection(int begin, int end) {
            if (begin > end || begin < 0 || end < 0 || end >= _size) {
                throw out_of_range("Invalid erase section");
            }
            int count = end - begin  + 1;
            for (int i = end + 1; i < _size; i++) {
                data[i - count] = data[i];
            }
            _size -= count;
        }

        Vector& operator=(const Vector& rhs) {
            if (this == &rhs) {
                return *this;
            }
            else {
                clear();
                resize(rhs._capacity);
                for (int i = 0; i < rhs._size; i++) {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        Vector& operator=(Vector&& rhs) {
            if (this == &rhs) {
                return *this;
            }

            delete[] data;
            data = rhs.data;
            rhs.data = nullptr;
            rhs._capacity = 0;
            rhs._size = 0;

            return *this;
        }

        bool operator==(const Vector& rhs) const {
            if (_size != rhs._size) {
                return false;
            }

            for (int i = 0; i < _size; i++) {
                if (data[i] != rhs.data[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Vector& rhs) const {
            return !(*this==rhs);
        }

        ~Vector() {
            delete[] data;
        }

        const int* begin() const {
            return &data[0];
        }

        const int* end() const {
            return &data[_size];
            
        }

        T* begin()  {
            return &data[0];
        }

        T* end()  {
            return &data[_size];   
        }

        const T* rbegin() const {
            return data + _size - 1;
        }

        const T* rend() const {
            return data - 1; 
        }

        T* rbegin()  {
            return data + _size - 1;
        }

        T* rend()  {
            return data - 1;
        }
        
        
        void swap(Vector& other) {
            std::swap(data, other.data);
            std::swap(_size, other._size);
            std::swap(_capacity, other._capacity);
        }

        void assign(int n, int value) {
            resize(n);
            for (int i = 0; i < n; i++) {
                data[i] = value;
            }
            _size = n;
        }

};
