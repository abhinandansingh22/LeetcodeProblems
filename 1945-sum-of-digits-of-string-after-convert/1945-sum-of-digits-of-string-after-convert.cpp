class Solution {
public:
    int getLucky(string s, int k) {
        vector<string> s1;
        int turn = 1;
        int i=0;
        string s2="";
        for (char val : s) {
            int dataPos = (int(val) - 96);
            s2+=to_string(dataPos);
            i++;
        }
        
        int sum;
        while (turn <= k) {
            sum=0;
            for(char x:s2){
                sum=sum+int(x)-'0';
            }
            s2="";
            s2=to_string(sum);
            turn++;
        }
        return sum;
    }
};