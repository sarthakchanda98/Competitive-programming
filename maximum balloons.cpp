class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        string s = "balloon";
        string checker = "";
        int minimum = INT_MAX;
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            count = 0;
            for(int j = 0;j<text.size();j++)
            {
                if(text[j] == s[i])
                {
                    count++;
                }
            }
            if(s[i] == 'l' || s[i] == 'o')
                {
                    count/=2;
                }
            minimum = min(minimum,count);
        }
        return minimum;
    }
};
