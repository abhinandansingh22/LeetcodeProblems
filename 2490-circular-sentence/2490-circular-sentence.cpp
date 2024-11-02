class Solution {
public:
    bool isCircularSentence(string sentence) {
        // last character of word==first character of first word
        if(sentence.front()!=sentence.back())
            return false;
        // last character of word==first character of next 
        size_t pos=0;
        
        while ((pos=sentence.find(' ', pos))!=string::npos) {
            if(sentence[pos-1]!=sentence[pos+1])
                return false;
            ++pos;
        }

        return true;
    }
};