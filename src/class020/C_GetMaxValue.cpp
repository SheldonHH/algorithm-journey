#include <iostream>
#include <vector>
using namespace std;

// 用这个例子讲解递归如何执行
class GetMaxValue {
public:
    static int maxValue(const vector<int>& arr) {
        return f(arr, 0, arr.size() - 1);
    }

    // arr[l....r]范围上的最大值
    static int f(const vector<int>& arr, int l, int r) {
        if (l == r) {
            return arr[l];
        }
        int m = (l + r) / 2;
        int lmax = f(arr, l, m);
        int rmax = f(arr, m + 1, r);
        return max(lmax, rmax);
    }
};

int main() {
    vector<int> arr = {3, 8, 7, 6, 4, 5, 1, 2};
    cout << "数组最大值 : " << GetMaxValue::maxValue(arr) << endl;
    return 0;
}
