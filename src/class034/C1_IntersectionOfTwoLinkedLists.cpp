#include <iostream>

using namespace std;

// 返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode-cn/problems/intersection-of-two-linked-lists/
struct ListNode {
    int val;
    ListNode *next;
};

ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
    if (h1 == nullptr || h2 == nullptr) {
        return nullptr;
    }
    ListNode *a = h1, *b = h2;
    int diff = 0;
    while (a->next != nullptr) {
        a = a->next;
        diff++;
    }
    while (b->next != nullptr) {
        b = b->next;
        diff--;
    }
    if (a != b) {
        return nullptr;
    }
    if (diff >= 0) {
        a = h1;
        b = h2;
    } else {
        a = h2;
        b = h1;
    }
    diff = abs(diff);
    while (diff-- != 0) {
        a = a->next;
    }
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}

// For testing purpose, not to be submitted.
int main() {
    // Test cases can be added here.
    return 0;
}
