class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        string shortest;
        bool flag = false;
        int c = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                flag = true;
                c++;
            }
        }

        if(c < k)
        {
            return "";
        }

        if(!flag)
        {
            return "";
        }

        int count;

        for(int i = 0; i < s.size(); i++)
        {
            count = 0;

            if(s[i] == '0')
                continue;

            else if(s[i] == '1')
            {
                for(int j = i; j < s.size(); j++)
                {
                    if(s[j] == '1')
                    {
                        count++;
                    }

                    if(count == k)
                    {
                        string current = s.substr(i, (j - i) + 1);

                        if(shortest.empty() ||
                           current.size() < shortest.size() ||
                           (current.size() == shortest.size() && current < shortest))
                        {
                            shortest = current;
                        }
                    }
                }
            }
        }

        return shortest;
    }
};