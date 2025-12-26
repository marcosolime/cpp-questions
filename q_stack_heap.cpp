#include <iostream>

int* f(){
    int* p = new int(4); // allocate on heap

    return p; // returned to caller
}

int main(){

    int* p = f();
    std::cout << *p << std::endl;
    delete p; // free heap memory

    std::cout << "Hello\n";

}