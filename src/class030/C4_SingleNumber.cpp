#include <iostream>
#include <vector>
using namespace std;

// In the array, one number appears an odd number of times, 
// while other numbers appear an even number of times.
// Return the number that appears an odd number of times.
int singleNumber(vector<int>& nums) {
    int eor = 0;
    for (int num : nums) {
        eor ^= num;
    }
    return eor;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example
    cout << singleNumber(nums) << endl; // Expected output: 4
    return 0;
}
