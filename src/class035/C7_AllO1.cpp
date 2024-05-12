#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iterator>
using namespace std;

// 全O(1)的数据结构
class AllOne {
    struct Bucket {
        unordered_set<string> set;
        int cnt;
        Bucket* last;
        Bucket* next;

        Bucket(const string& s, int c) : cnt(c), last(nullptr), next(nullptr) {
            set.insert(s);
        }
    };

    // 插入新桶
    void insert(Bucket* cur, Bucket* pos) {
        pos->next = cur->next;
        cur->next->last = pos;
        cur->next = pos;
        pos->last = cur;
    }

    // 删除桶
    void remove(Bucket* cur) {
        cur->last->next = cur->next;
        cur->next->last = cur->last;
        delete cur;
    }

    Bucket* head;
    Bucket* tail;
    unordered_map<string, Bucket*> map;

public:
    AllOne() {
        head = new Bucket("", 0);
        tail = new Bucket("", INT_MAX);
        head->next = tail;
        tail->last = head;
    }

    ~AllOne() {
        Bucket* cur = head;
        while (cur) {
            Bucket* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void inc(const string& key) {
        if (!map.count(key)) {
            if (head->next->cnt == 1) {
                map[key] = head->next;
                head->next->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, 1);
                map[key] = newBucket;
                insert(head, newBucket);
            }
        } else {
            Bucket* bucket = map[key];
            if (bucket->next->cnt == bucket->cnt + 1) {
                map[key] = bucket->next;
                bucket->next->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, bucket->cnt + 1);
                map[key] = newBucket;
                insert(bucket, newBucket);
            }
            bucket->set.erase(key);
            if (bucket->set.empty()) {
                remove(bucket);
            }
        }
    }

    void dec(const string& key) {
        if (!map.count(key)) return;

        Bucket* bucket = map[key];
        if (bucket->cnt == 1) {
            map.erase(key);
        } else {
            if (bucket->last->cnt == bucket->cnt - 1) {
                map[key] = bucket->last;
                bucket->last->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, bucket->cnt - 1);
                map[key] = newBucket;
                insert(bucket->last, newBucket);
            }
        }
        bucket->set.erase(key);
        if (bucket->set.empty()) {
            remove(bucket);
        }
    }

    string getMaxKey() const {
        if (tail->last == head) return "";
        return *tail->last->set.begin();
    }

    string getMinKey() const {
        if (head->next == tail) return "";
        return *head->next->set.begin();
    }
};
