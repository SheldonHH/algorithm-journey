#include <vector>
#include <queue>
#include <functional>

using namespace std;

// 合并K个有序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6

// 不要提交这个类
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 提交以下的方法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 小根堆
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);

        for (auto h : lists) {
            // 遍历所有的头！
            if (h != nullptr) {
                heap.push(h);
            }
        }
        if (heap.empty()) {
            return nullptr;
        }
        // 先弹出一个节点，做总头部
        ListNode* h = heap.top();
        heap.pop();
        ListNode* pre = h;
        if (pre->next != nullptr) {
            heap.push(pre->next); // 若还有加入 
        }
        while (!heap.empty()) {
            ListNode* cur = heap.top(); // 每次弹出一个节点
            heap.pop();
            // pre往下跳
            pre->next = cur; // 链接到总链表上
            pre = cur;
            if (cur->next != nullptr) {
                heap.push(cur->next); 
            }
        }
        return h;
    }
};
