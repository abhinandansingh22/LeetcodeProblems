class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        string s1,s2;
        int a,b;

        //Firstly compare each interger values before '.' in both strings
        while(i<version1.size() && j<version2.size())
        {
            s1="";
            while(version1[i]!='.' && i<version1.size())
            {
                s1+=version1[i];
                i++;
            }
            s2="";
            while(version2[j]!='.' && j<version2.size())
            {
                s2+=version2[j];
                j++;
            }
            i++;
            j++;
            a=stoi(s1);
            b=stoi(s2);
            if(a>b) return 1;
            else if(b>a) return -1;
        }

        //If the number of integers present in both strings are different, then any of the two while loop executes
        while(i<version1.size())
        {
            s1="";
            while(version1[i]!='.' && i<version1.size())
            {
                s1+=version1[i];
                i++;
            }
            int a=stoi(s1);
            if(a>0) return 1;
            i++;
        }
        while(j<version2.size())
        {
            s2="";
            while(version2[j]!='.' && j<version2.size())
            {
                s2+=version2[j];
                j++;
            }
            a=stoi(s2);
            if(a>0) return -1;
            j++;
        }
        return 0;
    }
};