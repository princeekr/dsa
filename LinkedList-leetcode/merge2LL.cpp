//21. Merge Two Sorted Lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t = new ListNode(-1);
        ListNode* tempc = t;

        while(list1 && list2){
            if(list1->val <= list2->val){
                tempc->next = list1;
                list1 = list1->next;
                tempc = tempc->next;
            }
            else{
                tempc->next = list2;
                list2 = list2->next;
                tempc = tempc->next;
            }
        }
        if(list1 == NULL) tempc->next = list2;
        else tempc->next = list1;
        
        return t->next;
    }
};