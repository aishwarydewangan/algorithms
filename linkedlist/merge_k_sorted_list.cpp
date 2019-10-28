/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct CustomSet {
    bool operator()(const ListNode *left, const ListNode *right) const {
        return left->val <= right->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }
        ListNode* root = NULL;
        
        set<ListNode*, CustomSet> nodes;
        
        for(auto node : lists) {
            while(node) {
                nodes.insert(node);
                node = node->next;
            }
        }
        
        
        if(nodes.empty()) {
            return NULL;
        }
        
        ListNode* temp = NULL;
        
        for(auto node : nodes) {
            if(root == NULL) {
                root = temp = node;
            } else {
                temp->next = node;
                temp = temp->next;
            }
            temp->next = NULL;
        }
        return root;
    }
};