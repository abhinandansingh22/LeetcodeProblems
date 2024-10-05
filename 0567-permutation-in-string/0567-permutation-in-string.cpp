class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        sort(s1.begin(),s1.end());
        int i=0;
        int j = 0;
        while(i<=m-n){
             string x=s2.substr(i,n);
             sort(x.begin(),x.end());
             if(x==s1) return true;
             i++;
            j++;

        }
        
        return false;
    }
};