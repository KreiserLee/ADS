#include <iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 用作头结点，不用于保存数据，且return不反回此节点
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        
        int carry = 0;
        while (l1 || l2 || carry) {
            // 只有当还有数据没处理完时，才会进入循环
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry%10);
            cur->next->next = NULL;
            cur = cur->next;
            carry /= 10;
        }
        return head->next;
    }
};

int main()
{
    ListNode *l1, *l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = NULL;
    
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);
    l2->next->next->next->next = NULL;
    
    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    while (result)
        cout << result->val << endl, result = result->next;
    
    return 0;
}