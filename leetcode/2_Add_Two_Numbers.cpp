/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *head, *prev;
        head = res;
        int a, b, c = 0;
        int sum = 0;
        while(l1 && l2) {
            prev = res;
            a = l1->val;
            b = l2->val;
            sum = a+b+c;
            res->val = sum%10;
            c = sum/10;
            res->next = new ListNode(0);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            prev = res;
            a = l1->val;
            sum = a+c;
            res->val = sum%10;
            c = sum/10;
            res->next = new ListNode(0);
            res = res->next;
            l1 = l1->next;
        }
        while(l2) {
            prev = res;
            b = l2->val;
            sum = b+c;
            res->val = sum%10;
            c = sum/10;
            res->next = new ListNode(0);
            res = res->next;
            l2 = l2->next;
        }
        if(c != 0) {
            res->val = c;
            return head;
        }
        prev->next = NULL;
        return head;
    }
};