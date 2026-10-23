// 143. Reorder List

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;

        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }        
        return prev;
    }

    void reorderList(ListNode* head) {
        //find the left middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; //break list into 2

        ListNode* c = new ListNode(-1);
        ListNode* tempa = a;
        ListNode* tempb = b;
        ListNode* tempc = c;

        // connections : fake node --> a then fake node --> b
        while(tempa && tempb){
            tempc->next = tempa;
            tempa = tempa->next;
            tempc = tempc->next;

            tempc->next = tempb;
            tempb = tempb->next;
            tempc = tempc->next;
        }
        tempc->next = tempa; //in the end, connect the list to lista
        head = c->next;
    }
};