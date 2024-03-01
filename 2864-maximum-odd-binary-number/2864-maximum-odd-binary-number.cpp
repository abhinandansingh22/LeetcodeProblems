class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i=0, j=0, n=s.size();
        while(j < n){
            if(s[j] == '1'){
                swap(s[i], s[j]);
                i++;
            }

            j++;
        }

        i = n-1;
        while(s[i] != '1') i--;
        swap(s[i], s[n-1]);

        return s;
    }
};