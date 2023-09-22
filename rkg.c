#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k);
void printList(struct ListNode* head);

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next = NULL;

    printf("Original list: ");
    printList(head);

    int k = 3;
    struct ListNode* newHead = reverseKGroup(head, k);

    printf("List after reversing every %d nodes: ", k);
    printList(newHead);

    return 0;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while (cur->next) {
        cur = cur->next;
        count++;
    }

    while (count >= k) {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
