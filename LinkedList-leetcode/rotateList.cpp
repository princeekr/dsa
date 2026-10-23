//61. Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;  //if list has 0/1 node then return head
        if(k==0) return head;  //k == 0 means no rotation so return the original head

        ListNode* temp = head;
        ListNode* tail = head;

        int len = 0;
        while(temp!=NULL){
            if(temp->next == NULL) tail = temp; //while calculating len we mark tail of list 
            len++;
            temp = temp->next;
        }

        k = k%len;   //to manage the huge vals of k

        temp = head;
        for(int i=1;i<len-k;i++){
            temp = temp->next;
        }

        //these are the main connections:
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};