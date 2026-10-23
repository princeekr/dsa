// 142. Linked List Cycle II

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false; 
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle == false) return NULL;
        else{
            ListNode* temp = head;
            while(temp!=slow){
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
    }
};