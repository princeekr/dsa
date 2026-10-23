// 160. Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;        
        ListNode* tempB = headB;

        int lengthA = 0;  
        while(tempA != NULL){
            lengthA ++;
            tempA = tempA->next;
        }

        int lengthB = 0;  
        while(tempB != NULL){
            lengthB ++;
            tempB = tempB->next;
        }

        tempA = headA;   
        tempB = headB;

        if(lengthA > lengthB){
            int diff = lengthA - lengthB;
            for(int i=1;i<=diff;i++){
                tempA = tempA->next;
            }
            while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;
        }
        else{
            int diff = lengthB - lengthA;
            for(int i=1;i<=diff;i++){
                tempB = tempB->next;
            }
            while(tempB != tempA){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempB;
        }
    }
};