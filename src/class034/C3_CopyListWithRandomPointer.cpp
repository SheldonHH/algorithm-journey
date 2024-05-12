#include <iostream>
#include <unordered_map>

using namespace std;

// 复制带随机指针的链表
// 测试链接 : https://leetcode-cn/problems/copy-list-with-random-pointer/
struct Node {
    int val;
    Node *next;
    Node *random;

    Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node *cur = head;
    Node *next = nullptr;
    // 1 -> 2 -> 3 -> ...
    // 变成 : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...
    while (cur != nullptr) {
        next = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    Node *copy = nullptr;
    // 利用上面新老节点的结构关系，设置每一个新节点的random指针
    while (cur != nullptr) {
        next = cur->next->next;
        copy = cur->next;
        copy->random = cur->random != nullptr ? cur->random->next : nullptr;
        cur = next;
    }
    Node *ans = head->next;
    cur = head;
    // 新老链表分离 : 老链表重新连在一起，新链表重新连在一起
    while (cur != nullptr) {
        next = cur->next->next;
        copy = cur->next;
        cur->next = next;
        copy->next = next != nullptr ? next->next : nullptr;
        cur = next;
    }
    // 返回新链表的头节点
    return ans;
}

// For testing purpose, not to be submitted.
int main() {
    // Test cases can be added here.
    return 0;
}
