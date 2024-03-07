class Solution {
public:
    int getlength(ListNode*head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int n=getlength(head);
        for(int i=1;i<=n/2;i++){
            head=head->next;
        }
        return head;
        
    }
};