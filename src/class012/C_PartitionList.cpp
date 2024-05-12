class Solution {  
public:  
    ListNode* partition(ListNode* head, int x) {  
        ListNode*  sHead = nullptr; // < x的区域  
        ListNode* sTail = nullptr; // >=x 的区域  
        ListNode* bHead = nullptr;  
        ListNode* bTail = nullptr;  
        ListNode* next = nullptr;  
  
        while (head != nullptr) {  
            // 6 5 3 4 2 1 1 7.   x = 4  
            next = head->next; // 记住之后向下跳  
            head->next = nullptr;  
            if (head->val < x) {  
                if ( sHead == nullptr) {   // 首次
                     sHead = head;  
                    sTail = head;  
                } else {  
                    sTail->next = head;  
                    sTail = head;  
                }  
            } else {  
                if (bHead == nullptr) {  
                    bHead = head;  
                    bTail = head;  
                } else {  
                    bTail->next = head;  
                    bTail = head;  
                }  
            }  
            head = next;  
        }  
  		//写法1
        if (sTail != nullptr) {  
            sTail->next = bHead;  
        }  
        return  sHead ?  sHead : bHead;  


		// 写法2
        if (sTail == nullptr) {  
            return bHead;  
        }  
        sTail->next = bHead;  
        return  sHead; 
    }  
};  
