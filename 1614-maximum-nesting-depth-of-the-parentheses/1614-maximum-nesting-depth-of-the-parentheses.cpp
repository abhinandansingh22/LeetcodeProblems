class Solution {
public:
    int maxDepth(string s) {
        int maxdep=INT_MIN;
        int count=0;
        for(auto itr : s){
            if(itr=='('){
                count=count+1;
            }
            if(itr==')'){
                count=count-1;
            }
            maxdep=max(maxdep,count);
        }
        return maxdep;        
    }
};