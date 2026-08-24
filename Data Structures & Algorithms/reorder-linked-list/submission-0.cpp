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
    void reorderList(ListNode* head) {
        /**
            Algorithm:
            - must reorder the linked list in the order such that
            - [0, n-1, 1, n-2, 2, n-3, ...]
            - cannot modify the values
            
            1. Find the midpoint
            2. Reverse the second half
            3. Join them
        **/

        // base case
        if (head == nullptr || head->next == nullptr){
            return;
        }

        // find middle of linked list
        // using fast and slow pointers
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // reverse second half
        ListNode* preMiddle = p1;
        ListNode* preCurrent = p1->next;

        while(preCurrent->next != NULL){
            ListNode* current = preCurrent->next;
            preCurrent -> next = current->next;
            current -> next = preMiddle->next;
            preMiddle->next = current;
        }

        // start reordering
        // using two pointers
        p1 = head;
        p2 = preMiddle->next;
        while(p1 != preMiddle){
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }

    }
};
