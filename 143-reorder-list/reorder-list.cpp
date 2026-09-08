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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* second = curr->next;
            curr->next = prev;
            prev = curr;
            curr = second;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        //get LL half with slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse second half of the LL
        ListNode* head2 = reverseLL(slow);
        
        //merge both halfs
        while(head2->next != nullptr) {
            //add node from list 1
            ListNode* tmp = head->next;
            head->next = head2;
            head = tmp;
            
            //add node from list 2
            tmp = head2->next;
            head2->next = head;
            head2 = tmp;
        }
    }
};