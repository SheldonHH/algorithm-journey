#include <vector>
#include <iostream>
using namespace std;

namespace class071 {

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    // sums[i] : 以i开头并且长度为k的子数组的累加和
    vector<int> sums(n);
    for (int l = 0, r = 0, sum = 0; r < n; r++) {
        sum += nums[r];
        if (r - l + 1 == k) {
            sums[l] = sum;
            sum -= nums[l];
            l++;
        }
    }
    // prefix[i] :
    // 0~i范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
    vector<int> prefix(n, 0);
    for (int l = 1, r = k; r < n; l++, r++) {
        if (sums[l] > sums[prefix[r - 1]]) {
            prefix[r] = l;
        } else {
            prefix[r] = prefix[r - 1];
        }
    }
    // suffix[i] :
    // i~n-1范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
    vector<int> suffix(n, 0);
    suffix[n - k] = n - k;
    for (int l = n - k - 1; l >= 0; l--) {
        if (sums[l] >= sums[suffix[l + 1]]) {
            suffix[l] = l;
        } else {
            suffix[l] = suffix[l + 1];
        }
    }
    int a = 0, b = 0, c = 0, max = 0;
    // 0...i-1    i...j    j+1...n-1
    //   左     中(长度为k)     右
    for (int p, s, i = k, j = 2 * k - 1, sum; j < n - k; i++, j++) {
        // 0.....i-1   i.....j  j+1.....n-1
        // 最好开头p      i开头     最好开头s
        p = prefix[i - 1];
        s = suffix[j + 1];
        sum = sums[p] + sums[i] + sums[s];
        if (sum > max) {
            max = sum;
            a = p;
            b = i;
            c = s;
        }
    }
    return {a, b, c};
}

} // namespace class071
