#include <iostream>
#include <vector>
using namespace std;

// Find the missing number
int missingNumber(vector<int>& nums) {
    int eorAll = 0, eorHas = 0;
    for (int i = 0; i < nums.size(); i++) {
        eorAll ^= i;
        eorHas ^= nums[i];
    }
    eorAll ^= nums.size();
    return eorAll ^ eorHas;
}

int main() {
    vector<int> nums = {3, 0, 1}; // Example
    cout << missingNumber(nums) << endl; // Expected output: 2
    return 0;
}
