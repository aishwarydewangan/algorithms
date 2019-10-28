/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head or !head->next) {
            return head;
        }
        
        int len = 0;
        
        ListNode* root = head;
        
        while(root) {
            len++;
            root = root->next;
        }
        
        ListNode *front = NULL, *end = NULL;
        
        if(len/k) {
            
            int t = len/k;
            
            while(t--) {
                int i = k;
                
                ListNode *f = NULL, *e = NULL;
                
                while(i--) {
                    ListNode* temp = head; 
                    
                    if(!f) {
                        f = e = head;
                        head = head->next;
                        e->next = NULL;
                    } else {
                        head = head->next;
                        temp->next = f;
                        f = temp;
                    }
                }
                
                if(front and end) {
                    end->next = f;
                    end = e;
                }
                
                if(!front and !end) {
                    front = f;
                    end = e;
                }
            }
            end->next = head;
            return front;
        }
        return head;
    }
};