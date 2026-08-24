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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            Naive Approach:
            - calculate length of linked list
            - directly delete the node from the back
        */

        ListNode* cur = head;
        ListNode* previous = nullptr;
        int length = 0;

        // length of linked list
        while (cur != nullptr){
            length++;
            cur = cur->next;
        }

        // reset cur
        cur = head;
        
        // case 1: end to be deleted
        if (n == length){
            head = cur->next;
            delete cur;
            return head;
        }

        int position = length - n + 1;
        // case 2: normal nth node deletion
        // move temp to target node, and prev to node before it
        for (int i = 1; i < position; i++){
            previous = cur;
            cur = cur->next;
        }

        // delete node at position n
        previous->next = cur->next;
        delete cur;

        return head;
    }
};
