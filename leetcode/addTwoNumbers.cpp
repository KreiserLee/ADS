// �ٶȸ��죬���Ǵ��벻�淶��ֱ����l1�ϲ���������l1��Ϊ�������
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
        ListNode* result = l1;
        ListNode* l1End = NULL;
        
        // the sum store in l1.
        // ������ӵĽ�����浽l1��
        while (l1 && l2) {
            l1->val += l2->val;
            l1End = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // if l2 is longer than l1, then add the rest of l2 to the end of l1.
        // ���l1 �� l2 һһ����꣬l2�л�����δ��������l2ʣ��Ĳ���ֱ�Ӽӵ�l1β����
        if (!l1) {
            l1End->next = l2;    
        }
        
        // do the mod
        // �ֱ��ÿ���ڵ㣨�ӵ�λ����λ�����н�λ
        l1 = result;
        int addNum = 0;
        ListNode* end;
        while (l1) {
            l1->val += addNum;
            addNum = 0;
            if (0 < l1->val / 10) {
                addNum = l1->val / 10;
                l1->val = l1->val % 10;
            }
            end = l1;
            l1 = l1->next;
        }
        
        // if the highest node is bigger than 10, then new a  ListNode
        // �������������l1�Ľڵ��addNum(���ڱ����λ��) �Բ�Ϊ0.���ʾ���λ��Ҫ��λ��
        // ����l1β����ӽڵ㣬���ڱ����λ����
        if (addNum > 0) {
            end->next = new ListNode(addNum);
            end->next->next = NULL;
        }
        return result;
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