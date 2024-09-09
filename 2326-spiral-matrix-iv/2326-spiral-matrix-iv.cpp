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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m , vector<int>(n , -1));

        int sc = 0 ; //start column
        int ec = n-1; //end column
        int sr = 0 ; //start row
        int er = m-1; //end row

        while(head != NULL){
            for(int i=sc ; i<=ec && head != NULL ; i++){
                ans[sr][i] = head->val;
                head = head->next ;
            }
            for(int i=sr+1 ; i<er && head != NULL ; i++){
                ans[i][ec] = head->val;
                head = head->next ;
            }
            for(int i=ec ; i>=sc && head != NULL ; i--){
                ans[er][i] = head->val;
                head = head->next ;
            }
            for(int i=er-1 ; i> sr && head != NULL ; i--){
                ans[i][sc] = head->val;
                head = head->next;
            }
            sc += 1 ; 
            ec -= 1 ;
            sr += 1 ;
            er -= 1 ;
        }

        return ans ;
    }
};