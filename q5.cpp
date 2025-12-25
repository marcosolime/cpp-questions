/*
What is undefined behaviour? Show one example in code.
it may:
- seem to work
- produce wrong results
- crash
- behave differently on another compiler
*/

#include <iostream>
using namespace std;

int main(){
    // 1) deferencing a null pointer
    int x = 10;
    int* p = nullptr;

    cout << *p << endl;

    // 2) out-of-bounds access
    int arr[4] = {1, 2, 3, 4};
    cout << arr[9];
}