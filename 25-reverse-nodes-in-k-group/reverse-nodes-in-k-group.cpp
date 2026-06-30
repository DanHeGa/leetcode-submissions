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
    ListNode* reverseLL(ListNode* head, int k) {
        int counter = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr && counter < k) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            counter++;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* tmp = head;
        int counter = 0;
        while(tmp && counter < k) {
            tmp = tmp->next;
            counter++;
        }

        if (counter != k) {
            return head; //not enough elements to reverse LL
        }

        ListNode* groupHead = reverseLL(head, k); //should have the head of the reverse LL k group

        head->next = reverseKGroup(tmp, k);

        return groupHead;
    }
};