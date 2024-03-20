class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int p1=0;
        ListNode*curr1=list1,*curr2=list1;
        while(p1<a-1 && curr1){
            p1+=1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(p1<b+1){
            p1+=1;
            curr2=curr2->next;
        }
        curr1->next=list2;
        while(curr1->next){
            curr1=curr1->next;
        }
        curr1->next=curr2;
        return list1;
    }
};