class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                char x=s[i];
                char y=s[j];
                while(s[i+1]==x && i+1<j) i++;
                while(s[j-1]==y && i<j-1) j--;
                i++,j--;
            }else{
                break;
            }
        }
        return (j-i+1);
    }
};
