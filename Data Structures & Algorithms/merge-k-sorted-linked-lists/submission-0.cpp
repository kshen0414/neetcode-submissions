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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /**
            Algo:
            - Min-Heap
            - Divide & Conquer
        **/
        auto compare = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // insert head of every non-empty linked list
        for (ListNode* head : lists){
            if(head != nullptr){
                minHeap.push(head);
            }
        }

        // Initialize dummy node and tail pointer
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (!minHeap.empty()){
            // Extract the smallest ListNode

            ListNode* node = minHeap.top();
            minHeap.pop();

            // append node to merged list
            tail->next = node;
            tail = node;

            // insert next node from same list
            if (node->next != nullptr){
                minHeap.push(node->next);
            }
        }

        tail -> next = nullptr;
        return dummy.next;
    }
};
