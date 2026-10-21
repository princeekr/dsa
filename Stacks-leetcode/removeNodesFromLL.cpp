// 2487. Remove Nodes From Linked List

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* Next = head;
        ListNode* prev = NULL;

        while(curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            while(st.size() > 0 && st.top()->val < temp->val) st.pop();
            st.push(temp);
            temp = temp->next;
        }

        ListNode* t = new ListNode(-1);
        temp = t;
        while(st.size()>0){
            ListNode* top = st.top();
            st.pop();
            temp->next = top;
            temp = top;
        }
        temp->next = NULL;
        return reverseList(t->next);
    }
};