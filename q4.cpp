/*
Q4. Implement RAII using a simple file handler class.

RAII (Resource Acquisition Is Initialization)
- a resource is acquired in a constructor
- the resource is released in the destructor
- lifetime of the resource is tied to object scope
*/

#include <cstdio>
#include <stdexcept>

class FileHandler {
private:
    FILE* file;

public:
    // Constructor: acquire resource
    FileHandler(const char* filename, const char* mode) {
        file = fopen(filename, mode);
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    // Delete copy constructor & copy assignment
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    // Move constructor
    FileHandler(FileHandler&& other) noexcept : file(other.file) {
        other.file = nullptr;
    }

    // Move assignment
    FileHandler& operator=(FileHandler&& other) noexcept {
        if (this != &other) {
            fclose(file);
            file = other.file;
            other.file = nullptr;
        }
        return *this;
    }

    // Destructor: release resource
    ~FileHandler() {
        if (file) {
            fclose(file);
        }
    }

    // Write to file
    void write(const char* text) {
        if (!file) {
            throw std::runtime_error("File not open");
        }
        fputs(text, file);
    }
};

int main() {
    try {
        FileHandler f("example.txt", "w");
        f.write("Hello RAII!\n");
    } catch (const std::exception& e) {
        // File is safely closed if constructor fails
    }
}
