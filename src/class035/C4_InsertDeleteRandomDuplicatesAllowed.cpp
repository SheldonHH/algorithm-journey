#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> map;
    vector<int> arr;

    RandomizedCollection() {
        // 初始化随机数种子
        srand(time(0));
    }

    bool insert(int val) {
        arr.push_back(val);
        unordered_set<int>& set = map[val]; // 使用引用以直接修改map中的集合
        set.insert(arr.size() - 1);
        return set.size() == 1; // 当集合只有一个元素时，返回true
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false; // 若map中没有此值，则无法删除
        }

        unordered_set<int>& valSet = map[val];
        int valAnyIndex = *valSet.begin(); // 获取集合中任意一个位置
        int endValue = arr.back();

        if (val == endValue) {
            valSet.erase(arr.size() - 1); // 若删除的是最后一个元素，则直接移除
        } else {
            unordered_set<int>& endValueSet = map[endValue];
            endValueSet.insert(valAnyIndex); // 将末尾元素移到val的位置
            arr[valAnyIndex] = endValue;
            endValueSet.erase(arr.size() - 1); // 移除末尾的旧索引
            valSet.erase(valAnyIndex);
        }

        arr.pop_back();

        if (valSet.empty()) {
            map.erase(val); // 如果集合为空，将其从map中移除
        }

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % arr.size();
        return arr[randomIndex]; // 返回随机索引的元素
    }
};
