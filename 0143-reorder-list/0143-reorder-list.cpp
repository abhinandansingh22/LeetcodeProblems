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
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            q.push_back(tmp);
            tmp=tmp->next;
            q.back()->next=NULL;
        }
        q.pop_front();
        bool f=1;
        while(!q.empty())
        {
            if(!f)
            {
                head->next=q.front();
                q.pop_front();
            }
            else
            {
                head->next=q.back();
                q.pop_back();
            }
            head=head->next;
            f=!f;
        }
    }
};