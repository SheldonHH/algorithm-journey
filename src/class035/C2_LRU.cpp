#include <unordered_map>
using namespace std;

class LRUCache {
    struct DoubleNode {
        int key;
        int val;
        DoubleNode *last;
        DoubleNode *next;

        DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
    };

    class DoubleList {
        DoubleNode *head;
        DoubleNode *tail;

    public:
        DoubleList() : head(nullptr), tail(nullptr) {}

        void addNode(DoubleNode *newNode) {
            if (newNode == nullptr) {
                return;
            }
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->last = tail;
                tail = newNode;
            }
        }

        void moveNodeToTail(DoubleNode *node) {
            if (tail == node) {
                return;
            }
            if (node == head) {
                head = node->next;
                if (head) head->last = nullptr;
            } else {
                node->last->next = node->next;
                if (node->next) node->next->last = node->last;
            }
            node->next = nullptr;
            node->last = tail;
            tail->next = node;
            tail = node;
        }

        DoubleNode* removeHead() {
            if (head == nullptr) {
                return nullptr;
            }
            DoubleNode *ans = head;
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = ans->next;
                head->last = nullptr;
                ans->next = nullptr;
            }
            return ans;
        }
    };

    unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList nodeList;
    int capacity;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (keyNodeMap.count(key)) {
            DoubleNode *node = keyNodeMap[key];
            nodeList.moveNodeToTail(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyNodeMap.count(key)) {
            DoubleNode *node = keyNodeMap[key];
            node->val = value;
            nodeList.moveNodeToTail(node);
        } else {
            if (keyNodeMap.size() == capacity) {
                DoubleNode *removedNode = nodeList.removeHead();
                keyNodeMap.erase(removedNode->key);
                delete removedNode;
            }
            DoubleNode *newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            nodeList.addNode(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
