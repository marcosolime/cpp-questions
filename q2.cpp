/*
Write a C++ function that returns the largest element
in a vector
*/
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int largestElement(const vector<int>& v){
    // empty vector? -> throw error
    if (v.empty()) {
        throw runtime_error("Vector is empty");
    }

    int maxVal = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }
    return maxVal;
}

int main(){

    vector<int> nums = {}; //{3, 5, 62, 3, 55};
    int ans = largestElement(nums);
    cout << ans << endl;

    return 0;
}
