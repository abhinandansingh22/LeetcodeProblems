class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode*> T = {};
        vector<ListNode*> TT = {};
        int cur = 0;
        ListNode* n = head;

        while (n != nullptr) {
            TT = {};
            cur += n->val;
            if (cur == 0) {
                TT = {}; 
                cur = 0;   
            }
            else {
                int tcur = cur;
                int i = 0;
                for (; i < T.size(); i++) {
                    ListNode* cn = T[i];
                    tcur -= cn->val;
                    TT.push_back(cn);
                    if (tcur == 0) {   
                        break;
                    }
                }
                if (i >= T.size()) {
                    TT.push_back(n);
                }
                cur = 0;
                for (auto cn : TT) {
                    cur += cn->val;
                }
            }
            n = n->next;
            T = TT;
        }
        if (T.size() == 0)
            return nullptr;
        for (int i = 1; i < T.size(); i++) {
            T[i - 1]->next = T[i];
        }
        T[T.size() - 1]->next = nullptr;
        return T[0];
    }
};