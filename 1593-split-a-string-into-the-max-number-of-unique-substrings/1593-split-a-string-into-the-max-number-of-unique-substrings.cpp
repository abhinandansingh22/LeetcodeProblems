class Solution {
private:  
    int fun(int idx,int n,string &s,string temp,unordered_set<string>&st){
        if(idx==n){
            return 0;
        }
        temp+=s[idx];
        int nottake=fun(idx+1,n,s,temp,st);
        int take=0;
        if(st.find(temp)==st.end()){
            st.insert(temp);
            take=1+fun(idx+1,n,s,"",st);
            st.erase(temp);
        }
        return max(take,nottake);
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int n=s.length();
        return fun(0,n,s,"",st);
        
    }
};