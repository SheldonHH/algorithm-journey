#include <iostream>
#include <vector>
using namespace std;

// A generic function to find the number that appears less than m times
// when all other numbers appear exactly m times.
int find(const vector<int>& arr, int m) {
    // Initialize a counter for each bit position
    vector<int> cnts(32, 0);
    
    // Count the number of 1s at each bit position across all numbers
    for (int num : arr) {
        for (int i = 0; i < 32; i++) {
            cnts[i] += (num >> i) & 1;
        }
    }

    int ans = 0;
    // Use the modulo operation to determine which bits should be set in the result
    for (int i = 0; i < 32; i++) {
        if (cnts[i] % m != 0) {
            ans |= (1 << i);
        }
    }

    return ans;
}

int singleNumber(const vector<int>& nums) {
    return find(nums, 3);
}

int main() {
    vector<int> nums = {2, 2, 3, 2}; // Example
    cout << singleNumber(nums) << endl; // Expected output: 3
    return 0;
}
