class Solution {
public:
    #define ll long long

    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int findTheLongestSubstring(string s) {
        ll n=s.length(),mask=0,answer=0;
        unordered_map<ll,ll>mp;mp[0]=-1;
        unordered_map<char,ll>ss;ss['a']=0;ss['e']=1;ss['i']=2;ss['o']=3;ss['u']=4;
        for(ll i=0;i<n;i++){
            if(isvowel(s[i])){
                mask=mask^(1<<(ss[s[i]]));
            }
            if(mp.find(mask)!=mp.end()){
                answer=max(answer,i-mp[mask]);
            }
            else{
                mp[mask]=i;
            }
        }
        return answer;    
    }
};