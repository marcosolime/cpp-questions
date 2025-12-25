/*
Q6. Difference between unique_ptr and shared_ptr with example.
*/
#include <iostream>
#include <memory>
using namespace std;

/*
std::unique_ptr
    - exclusive ownership of an object
    - only one unique_ptr cna own the resource at a time
    - cannot be copied, only moved

std::shared_ptr
    - shared ownership using reference couting
    - resource is freed when the last owner releases it
    - can be copied
*/

int main() {
    /*
    unique_ptr<int> p1 = make_unique<int>(10);

    // unique_ptr<int> p2 = p1;

    unique_ptr<int> p2 = std::move(p1);

    cout << *p2 << endl;
    // p1 is now nullptr
    // cout << p1 << endl;
    */

    shared_ptr<int> p1 = make_shared<int>(20);
    shared_ptr<int> p2 = p1;

    cout << *p1 << " " << *p2 << endl;  // 20 20
    cout << p1.use_count() << endl;     // 2

    p2.reset();
    cout << p1.use_count() << endl;
}