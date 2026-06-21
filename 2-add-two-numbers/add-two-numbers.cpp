/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* aux = res;

        while(l1 || l2) {
            int sum = 0;

            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            sum = l1Val + l2Val + carry;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            carry = sum / 10;
            int num = sum % 10;

            aux->next = new ListNode(num);
            aux = aux->next;
        }

        if (carry != 0) {
            ListNode* lastCarry = new ListNode(carry);
            aux->next = lastCarry;
        }

        return res->next;
    }
};