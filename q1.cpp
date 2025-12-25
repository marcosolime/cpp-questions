/*
Implement a function that safely swaps two integers
using references
*/
#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 4;
    int b = 6;

    std::cout<<"before: a="<<a<<"; b="<<b<<endl;
    swap(a,b);
    std::cout<<"after: a="<<a<<"; b="<<b<<endl;

    return 0;
}
