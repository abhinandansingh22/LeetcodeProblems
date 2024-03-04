class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        int mxscore=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                mxscore=max(score,mxscore);
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        return mxscore;
    }
};