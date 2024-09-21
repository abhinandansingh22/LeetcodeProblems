class Solution {
public:
    vector<int> ans;
    void solve(int i, int n, int cnt){
        if(cnt > n) return;
        if(cnt <= n) ans.push_back(cnt);
        for(int i = 0; i <= 9; i++){
            solve(i, n, cnt*10+i);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++){
            solve(i, n, i);
        }

        return ans;
    }
};