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

 /**
  1. creates empty node
  ListNode() : val(0), next(nullptr){}
  - means we create an initial node with val == 0, next == nullptr
 
  2. create node with value
  ListNode(int x) : val(x), next(nullptr) {}
  - means we create an initial node with val == x, next == nullptr

  3. creates node with link
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  - means we create a node with a value and next pointer
 **/

 /**
    ListNode* b = new ListNode(8);

    ListNode* a = new ListNode(5, b);

    'a' node will point to 'b' node...
 **/

 /**
    so in order for two nodes to connect

    node x's next part, must contain mem address of node y's mem addres
 **/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* previous = NULL;

        while(cur != NULL){
            next = cur -> next;
            cur -> next = previous;
            previous = cur;
            cur = next;
        }

        head = previous;  // at last head points to where previous points
        return head;
    }
};
