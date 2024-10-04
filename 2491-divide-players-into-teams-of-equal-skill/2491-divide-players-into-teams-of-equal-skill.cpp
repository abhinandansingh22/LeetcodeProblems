class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        vector<int>v;
        if(n%2!=0) return -1;
        sort(skill.begin(),skill.end());
        int i=0;int j=skill.size()-1;
        long long value=0;
        if(n==2) return skill[0]*skill[1];
        while(i<j)
        {
            int x=skill[i]+skill[j];
            v.push_back(x);
             value+=static_cast<long long>(skill[i])*skill[j];
            i++;j--;
        }
        bool ans=true;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]!=v[i-1])
            ans=false;
        }
        if(ans==false) return -1;
        else return value;

    }
};