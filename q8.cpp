
/*
Q8. Implement const-correct getter/setter methods.
*/
#include <string>
#include <iostream>
using namespace std;

class Cat {
private:
    string name;
    int age;

public:
    // Constructors
    Cat()
    : name("Unnamed"), age(0) {
        cout << "Constructor is called." << endl; 
    }

    Cat(const string& name, int age)
    : name(name), age(age) {
        cout << "Constructor is called." << endl;    
    }

    // Destructor
    ~Cat(){
        cout << "Cat destructor called." << endl;
    }

    // getters
    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // setters
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    // other methods
    void miao() const{
        cout << "Miao!" << endl;
    }

    void whoami() const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

};


int main(){
    Cat fufi;
    fufi.miao();
    fufi.whoami();

    fufi.setAge(4);
    cout << fufi.getAge() << endl;
}