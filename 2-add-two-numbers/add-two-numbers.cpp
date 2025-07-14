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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(-1);
        ListNode* root = l;
        int rem = 0;
        while(l1!=nullptr && l2!=nullptr){
            int a = l1->val;
            int b = l2->val;
            int sum = a+b+rem;
            int v = sum%10;
            rem = sum/10;
            ListNode* temp = new ListNode(v);
            l->next = temp;
            l = l->next;
            l1= l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            int a = l1->val;
            int sum = a+rem;
            int v = sum%10;
            rem = sum/10;
            ListNode* temp = new ListNode(v);
            l->next = temp;
            l = l->next;
            l1= l1->next;
        }
        while(l2!=nullptr){
            int b = l2->val;
            int sum = b+rem;
            int v = sum%10;
            rem = sum/10;
            ListNode* temp = new ListNode(v);
            l->next = temp;
            l = l->next;
            l2=l2->next;
        }
        while(rem>0){
            int sum = rem;
            int v = sum%10;
            rem = sum/10;
            ListNode* temp = new ListNode(v);
            l->next = temp;
            l = l->next;
        }
        return root->next;
    }
};