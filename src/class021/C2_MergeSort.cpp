#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 归并排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
class Code02_MergeSort {
public:
    static const int MAXN = 50001;
    static vector<int> help;

    // 归并排序递归版
    static void mergeSort1(vector<int>& arr) {
        sort(arr, 0, arr.size() - 1);
    }

    static void sort(vector<int>& arr, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    // 归并排序非递归版
    static void mergeSort2(vector<int>& arr) {
        int n = arr.size();
        for (int l, m, r, step = 1; step < n; step <<= 1) {
            l = 0;
            while (l < n) {
                m = l + step - 1;
                if (m + 1 >= n) {
                    break;
                }
                r = min(l + (step << 1) - 1, n - 1);
                merge(arr, l, m, r);
                l = r + 1;
            }
        }
    }

    static void merge(vector<int>& arr, int l, int m, int r) {
        int i = l;
        int a = l;
        int b = m + 1;
        while (a <= m && b <= r) {
            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while (a <= m) {
            help[i++] = arr[a++];
        }
        while (b <= r) {
            help[i++] = arr[b++];
        }
        for (i = l; i <= r; i++) {
            arr[i] = help[i];
        }
    }

    static vector<int> sortArray(vector<int>& nums) {
        if (nums.size() > 1) {
            // mergeSort1为递归方法
            // mergeSort2为非递归方法
            // 用哪个都可以
            mergeSort2(nums);
        }
        return nums;
    }
};

vector<int> Code02_MergeSort::help(Code02_MergeSort::MAXN);

int main() {
    vector<int> arr = {3, 8, 7, 6, 4, 5, 1, 2};
    vector<int> sorted = Code02_MergeSort::sortArray(arr);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
