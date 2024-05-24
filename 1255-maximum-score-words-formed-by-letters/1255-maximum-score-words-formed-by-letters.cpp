class Solution {
public:
    int ans=INT_MIN;
unordered_map<char,int>val;
unordered_map<char,int>freq;
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
{
	//getting the freq of all the avail char's
	for(int i=0;i<(letters.size());i++)
	{
		char ch = letters[i];
		freq[ch]++;
	}
	//getting the val of all the alphabets
	for(int i=0;i<(score.size());i++)
	{
		char ch = 'a' + i;
		val[ch] = score[i];
	}
	int idx=0;
	string temp="";
	fun(idx,temp,words,letters,score);
	return ans;
}
void fun(int idx,string &temp,vector<string>&words,vector<char>&letters,vector<int>&score)
{
	if(idx >= words.size())
	{
		//try to make the ans with the help of val and freq map
		unordered_map<char,int>temp_freq;
		for(int i=0;i<temp.length();i++)
		{
			char ch = temp[i];
			temp_freq[ch]++;
			
			if(temp_freq[ch] > freq[ch])
			{
				return;
			}
		}
		int sum=0;
		for(auto it=temp_freq.begin();it!=temp_freq.end();it++)
		{
		    sum = sum + (it->second * val[it->first]);	
		}
		if(sum > ans)
		ans=sum;
		return;
	}
	string prvstr=temp;
	
	temp=temp+words[idx];
	fun(idx+1,temp,words,letters,score);
	
	temp=prvstr;
	fun(idx+1,temp,words,letters,score);
}

};