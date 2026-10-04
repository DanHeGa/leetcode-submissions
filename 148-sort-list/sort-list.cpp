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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        //get both halfs (unordered at this point)
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* scndHalf = slow->next;
        slow->next = nullptr;
        
        //order both halfs
        ListNode* left = sortList(head);
        ListNode* right = sortList(scndHalf);

        //merge both sorted halfs
        ListNode* dummyHead = new ListNode(0); //dummy to reduce merge logic
        ListNode* curr = dummyHead;
        while(left && right) {
            if (left->val <=right->val) {
                curr->next = left;
                left = left->next;
            } else { //right->val < left->val
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if (left) {
            curr->next = left;
        } else if (right) {
            curr->next = right;
        }

        return dummyHead->next; //return sorted LL
    }
};