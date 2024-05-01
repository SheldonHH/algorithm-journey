#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 插入、删除和获取随机元素O(1)时间的结构
class RandomizedSet {
public:
    unordered_map<int, int> map;
    vector<int> arr;

    RandomizedSet() {
        // 初始化随机数生成器
        srand(time(0));
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        int valIndex = map[val];
        int endValue = arr.back();

        // 如果删除的不是最后一个元素，将最后一个元素移到删除位置
        if (val != endValue) {
            map[endValue] = valIndex;
            arr[valIndex] = endValue;
        }
        
        map.erase(val);
        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
