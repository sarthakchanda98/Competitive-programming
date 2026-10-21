class Solution {
public:
    int minOperations(string s) 
    {
        bool sorted = true;
        for(int i = 0;i<s.size()-1;i++)
        {
            if(s.at(i)>s.at(i+1))
            {
                sorted = false;
                break;
            }
        }
    if(sorted)
    {
        return 0;
    }
    if(s.size()==2 && (!sorted))
    {
        return -1;
    }
    char mn = *min_element(s.begin(), s.end());
    char mx = *max_element(s.begin(), s.end());
    if (s[0] == mn || s[s.size()- 1] == mx)
     {
            return 1;
     }
     for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
     return 3;
    }
};