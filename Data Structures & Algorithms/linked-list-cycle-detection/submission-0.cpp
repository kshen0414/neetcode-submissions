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
    bool hasCycle(ListNode* head) {
        /*
            Algorithm:
            - Start from head
            - move through linked list one node at a time
            - keep track of every node that has already been visited
            - before visiting a node
                - If node has been visted, cycle exists
                - else, remember the node and continue
            - if another case is reach NULL, then no cycle exists
        
        Discovered a new algorithm: Fast and Slow Pointers
            - No Loop, fast pointer eventually reaches NULL
            - Have a Loop, fast pointer will eventually catch up to the slow pointer
            - then will point to the same node
        */
        
        // hashset approach
        unordered_set<ListNode*> seen;
        ListNode* current = head;

        while(current){
            if(seen.find(current) != seen.end()){
                return true;
            }

            seen.insert(current);
            current = current->next;
        }

        return false;

    }
};
