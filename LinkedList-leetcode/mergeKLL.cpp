//23. Merge k Sorted Lists

class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b){
        ListNode* c = new ListNode(100);
        ListNode* t = c;
        while(a && b){
            if(a->val <= b->val){
                t->next = a;
                a = a->next;
                t = t->next;
            }
            else{
                t->next = b;
                b = b->next;
                t = t->next;
            }
        }
        if(a == NULL) t->next = b;
        else t->next = a;
        return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size() == 0) return NULL;
        while(arr.size() > 1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = mergeTwo(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};