class Solution {
public:

vector<string> break_into_words(string& sentence){
    vector<string> w;
    stringstream ss(sentence);
    string word;
    while(ss >> word){
        w.push_back(word);
    }

    return w;
}


bool areSentencesSimilar(string sentence1, string sentence2) {


    vector<string> wordList1 = break_into_words(sentence1);
    vector<string> wordList2 = break_into_words(sentence2);

    int n1(wordList1.size()), n2(wordList2.size()), front = 0, end = 0;


    while(front < n1 && front < n2 && wordList1[front] == wordList2[front]){
        front++;
    }

    while(end < n1 - front && end < n2 - front && wordList1[n1-end-1] == wordList2[n2-end-1]){
        end++;
    }

    return front + end == n1 || front + end == n2;
    
}
};