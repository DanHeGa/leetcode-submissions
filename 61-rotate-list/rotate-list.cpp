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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || head->next == nullptr) return head;

        int totalNodes = 0;
        ListNode* aux = head;
        while(aux != nullptr) {
            totalNodes++;
            aux = aux->next;
        }

        //case where k is more than the LL length
        k = k % totalNodes;
        if (k == 0) return head;

        //initialize fast and slow pointers
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        //slow has the end of the first half (break point at n - k nodes)
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};