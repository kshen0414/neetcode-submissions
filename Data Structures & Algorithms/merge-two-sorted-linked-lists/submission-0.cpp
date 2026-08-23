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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
            Algorithm:
            - list1 is the head of first sorted list
            - list2 is the head of second sorted list
            - Compare list1 and list2 nodes
                - determine which node is larger than append to new sorted linked list
                - need head pointer and tail pointer
        */
        ListNode* cur_1 = list1;
        ListNode* cur_2 = list2;
        ListNode* tail = NULL;
        ListNode* new_head = NULL;

        if(cur_1== NULL){
            return cur_2;
        }
        if(cur_2==NULL){
            return cur_1;
        }

        else if(cur_1->val > cur_2->val){
            new_head = cur_2;
            tail = cur_2;
            cur_2 = cur_2->next;
        }
        else{
            new_head = cur_1;
            tail = cur_1;
            cur_1 = cur_1->next;
        }

        while(cur_1 != NULL && cur_2 != NULL){
            if (cur_1 -> val > cur_2 -> val){
                tail->next = cur_2;  // connect
                tail = cur_2; // move tail
                cur_2 = cur_2 -> next;  // move cur_2's pointer
            }
            else{
                tail->next = cur_1; // connect
                tail = cur_1; // move tail
                cur_1 = cur_1 -> next;  // move cur_1's pointer
            }
        }

        if (cur_1 !=NULL){
            tail->next = cur_1;
        }
        else{
            tail->next = cur_2;
        }

        return new_head;

    }
};
