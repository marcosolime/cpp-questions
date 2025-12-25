/*
Explain and implement move constructor vs copy constructor
*/

/*
Copy constructor:
- create a new object by copying another object
- ClassName(const ClassName& other); 

Move constructor:
- create a new object by stealing resources from
a termporary object
- ClassName(ClassName&& other);

Takeway: copying duplicates memory; moving just transfer
ownership
*/

#include <iostream>
using namespace std;

class Buffer {
private:
    int* data;
    size_t size;

public:
    // Constructor
    Buffer(size_t s) : size(s) {
        data = new int[size];
        cout << "Constructor\n";
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Copy constructor\n";
    }

    // Move constructor (steal resources)
    Buffer(Buffer&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor\n";
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        cout << "Destructor\n";
    }

};

int main(){
    Buffer a(5);
    Buffer b(a); // copy constructor
    Buffer c = std::move(a); // move constructor
}