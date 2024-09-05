class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int s=accumulate(rolls.begin(),rolls.end(),0);
        int s1=(m+n)*mean - s;
        if(s1 <= 0 || s1/n == 0) return {};
        vector<int> ans(n);
        if(s1%n==0){
            if(s1/n > 6) return {};
            else{
                for(int i=0;i<n;++i){
                    ans[i]=(s1/n);
                }
            }
        }else{
            if(s1/n >= 6) return {};
            else{
                for(int i=0;i<n-1;++i){
                    ans[i]=(s1/n);
                }
                int l = (s1-(s1/n)*(n-1));
                if(l <= 6) ans[n-1]=l;
                else{
                    int ct=1;
                    for(int i=n-2;i>=0 && ct<=l-6;--i){
                        ans[i]++;
                        ct++;
                    }
                    ans[n-1]=6;
                }
            }
        }
        return ans;
    }
};