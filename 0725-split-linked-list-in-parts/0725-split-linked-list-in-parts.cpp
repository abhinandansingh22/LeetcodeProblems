/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode * temp=head;

        while(temp){
            temp=temp->next;
            size++;
        }

        int extraSized=size%k;
        int regularSized=size/k;

        vector<ListNode *> ans(k,NULL);

        int i=0;

        while(extraSized){
            ListNode *temp=head;
            ListNode *prev=NULL;

            for(int j=regularSized+1 ; j>0 ; j--){
                prev=head;
                head=head->next;
            }

            prev->next=NULL;
            ans[i]=temp;
            i++;
            extraSized--;    
        }

        while(head){
            ListNode *temp=head;
            ListNode *prev=NULL;

            for(int j=regularSized ; head && j>0 ; j--){
                prev=head;
                head=head->next;
            }

            prev->next=NULL;
            ans[i]=temp;
            i++;    
        }
        
        return ans;
    }
};