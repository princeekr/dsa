// 2. Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t = new ListNode(-1);
        ListNode* temp = t;
        int carry = 0;

        while(l1 || l2){
            int digit1 = (l1 != NULL) ? l1->val : 0;
            int digit2 = (l2 != NULL) ? l2->val : 0;
            
            int sum = digit1 + digit2 + carry;
            carry = sum/10;

            ListNode* x = new ListNode(sum%10);
            temp->next = x;
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry){
            ListNode* y = new ListNode(carry);
            temp->next = y;
        }
        return t->next;
    }
};
