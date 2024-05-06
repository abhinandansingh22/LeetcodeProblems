class Solution {
public:
    ListNode* reverse(ListNode* head) {
       ListNode* curr=head;
        ListNode * prev=NULL;
        ListNode * next1=NULL;
        while(curr != NULL){
        next1=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next1;
        }
        return prev ;
    }
    ListNode* removeNodes(ListNode* head) {
      head=reverse(head);
      ListNode* curr=head;
      ListNode* prev=NULL;
      int maxi=head->val;
      while(curr != NULL){
      maxi=max(maxi,curr->val);
      if(maxi > curr->val){
          prev->next=prev->next->next;
      }
          else 
          prev = curr;
          
          curr=curr->next;
      }
     return reverse(head);
      
    }
};