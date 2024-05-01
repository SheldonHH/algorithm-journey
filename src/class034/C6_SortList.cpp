#include <iostream>
using namespace std;

// 链表节点类
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* start = nullptr;  // 合并操作后的链表头
ListNode* end = nullptr;    // 合并操作后的链表尾

ListNode* findEnd(ListNode* s, int k) {
    // 返回链表段s的k个节点之后的节点或链表尾
    while (s != nullptr && s->next != nullptr && --k != 0) {
        s = s->next;
    }
    return s;
}

void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2) {
    // 合并两个已排序的链表段，并设置start为合并后链表的头，end为尾
    ListNode* pre = nullptr;

    if (l1->val <= l2->val) {
        start = l1;
        pre = l1;
        l1 = l1->next;
    } else {
        start = l2;
        pre = l2;
        l2 = l2->next;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            pre->next = l1;
            pre = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        }
    }

    if (l1 != nullptr) {
        pre->next = l1;
        end = r1;
    } else {
        pre->next = l2;
        end = r2;
    }
}

ListNode* sortList(ListNode* head) {
    // 计算链表长度
    int n = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
        n++;
        cur = cur->next;
    }

    for (int step = 1; step < n; step <<= 1) {
        // 第一组独立处理
        ListNode* l1 = head;
        ListNode* r1 = findEnd(l1, step);
        ListNode* l2 = r1 != nullptr ? r1->next : nullptr;
        ListNode* r2 = findEnd(l2, step) if l2 != nullptr : nullptr;
        ListNode* next = r2 != nullptr ? r2->next : nullptr;

        if (r1 != nullptr) r1->next = nullptr;
        if (r2 != nullptr) r2->next = nullptr;

        merge(l1, r1, l2, r2);

        head = start;
        ListNode* lastTeamEnd = end;

        while (next != nullptr) {
            l1 = next;
            r1 = findEnd(l1, step);
            l2 = r1 != nullptr ? r1->next : nullptr;

            if (l2 == nullptr) {
                lastTeamEnd->next = l1;
                break;
            }

            r2 = findEnd(l2, step);
            next = r2 != nullptr ? r2->next : nullptr;

            if (r1 != nullptr) r1->next = nullptr;
            if (r2 != nullptr) r2->next = nullptr;

            merge(l1, r1, l2, r2);

            lastTeamEnd->next = start;
            lastTeamEnd = end;
        }
    }

    return head;
}
