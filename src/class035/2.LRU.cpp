#include <unordered_map>
using namespace std;

// 实现LRU结构
class LRUCache {
public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            DoubleNode* node = keyNodeMap[key];
            moveNodeToTail(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            DoubleNode* node = keyNodeMap[key];
            node->val = value;
            moveNodeToTail(node);
        } else {
            if (keyNodeMap.size() == capacity) {
                keyNodeMap.erase(head->key);
                removeHead();
            }
            DoubleNode* newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            addNode(newNode);
        }
    }

private:
    struct DoubleNode {
        int key;
        int val;
        DoubleNode* last;
        DoubleNode* next;

        DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
    };

    void addNode(DoubleNode* newNode) {
        if (!newNode) return;
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->last = tail;
            tail = newNode;
        }
    }

    void moveNodeToTail(DoubleNode* node) {
        if (tail == node) return;
        if (head == node) {
            head = node->next;
            if (head) head->last = nullptr;
        } else {
            node->last->next = node->next;
            if (node->next) node->next->last = node->last;
        }
        node->last = tail;
        node->next = nullptr;
        if (tail) tail->next = node;
        tail = node;
    }

    void removeHead() {
        if (!head) return;
        DoubleNode* node = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            if (head) head->last = nullptr;
        }
        delete node;
    }

    unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleNode* head;
    DoubleNode* tail;
    int capacity;
};
