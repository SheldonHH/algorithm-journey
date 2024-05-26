#include <unordered_map>
using namespace std;

// 实现LRU结构
class LRUCache {
    // 链表头代表最早
    // 链表尾代表最晚
    struct DoubleNode {
        int key; // 节点的键
        int val; // 节点的值
        DoubleNode *last; // 指向前一个节点的指针
        DoubleNode *next; // 指向后一个节点的指针

        // 构造函数，初始化键和值，并将前后指针置空
        DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
    };

    class DoubleList {
        DoubleNode *head; // 链表头部
        DoubleNode *tail; // 链表尾部

    public:
        DoubleList() : head(nullptr), tail(nullptr) {}

        // 添加节点到尾部
        void addNode(DoubleNode *newNode) {
            if (newNode == nullptr) { // 捣乱的滚
                return;
            }
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->last = tail; // 指向老尾巴
                tail = newNode; // 你成为新尾巴
            }
        }

        // 将节点移动到尾部
        void moveNodeToTail(DoubleNode *node) {
            if (tail == node) { // 本来就是最晚最新被调用的
                return;
            }
            if (head == node) {
                head = node->next; // 头后移
                head->last = nullptr; // 头last指针标空，悬空
            } else {
                // 前节点的next指针指向我的后面
                node->last->next = node->next;
                // 我的下一个节点的last指针指向我的前面
                node->next->last = node->last;
            }
            // 我的last指向尾巴
            node->last = tail;
            // 我的next设置为null
            node->next = nullptr;
            // 尾巴的next指向node
            tail->next = node;
            // 你成为新尾巴
            tail = node;
        }

        // 移除头节点
        DoubleNode* removeHead() { // 空间不够了
            if (head == nullptr) { // 不用移除了
                return nullptr;
            }
            DoubleNode *ans = head;
            if (head == tail) { // 只有一个节点时
                head = nullptr;
                tail = nullptr;
            } else {
                // 下一个节点做头
                head = ans->next;
                // ans  head(左指向右断链)
                head->last = nullptr;
                // ans  head(右指向左断链)
                ans->next = nullptr;
            }
            return ans;
        }
    };

    unordered_map<int, DoubleNode*> keyNodeMap; // key对应节点的内存地址
    DoubleList nodeList; // 维持时间顺序的双向链表
    int capacity; // 缓存的容量

public:
    LRUCache(int cap) : capacity(cap) {}

    // 会修改时间，变成最晚的
    int get(int key) {
        if (keyNodeMap.count(key)) {
            DoubleNode *node = keyNodeMap[key];
            // 返回给用户之前，在时间序列上移动到尾巴上
            nodeList.moveNodeToTail(node);
            return node->val;
        }
        return -1; // 没记录
    }

    // 会修改时间，变成最晚的
    void put(int key, int value) {
        if (keyNodeMap.count(key)) { // 更新即可，无需真的插入
            DoubleNode *node = keyNodeMap[key];
            node->val = value;
            // 双向链表维持时序，就很爽，扔到尾部
            nodeList.moveNodeToTail(node);
        } else {
            // 新增操作要讨论空间满还是没满
            if (keyNodeMap.size() == capacity) {
                // 双向链表移出之后会返回，他的key在哈希表里面也删掉
                DoubleNode *removedNode = nodeList.removeHead();
                keyNodeMap.erase(removedNode->key); // 删掉之后头节点向下移动
                delete removedNode;
            }
            // 空间没问题
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
