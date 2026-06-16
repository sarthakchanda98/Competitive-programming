#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums)
    {
        vector<int> duplicates;
        int num;
        int res;
        bool flag = false;
        for(int i = 0;i<nums.size()-1;i++)
        {
            for(int j = i+1; j<nums.size();j++)
            {
                if(nums.at(j) == nums.at(i))
                {
                    duplicates.push_back(nums.at(i));
                    flag = true;
                }
            }
        }
        if(!flag)
        {
            return 0;
        }
        else
        {
            if(duplicates.size() == 1)
            {
                return duplicates[0];
            }
            res = duplicates[0];
            for(int i = 1; i<duplicates.size(); i++ )
            {
                res = res^duplicates.at(i);
            }
            return res;
        }
    }
};

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    cout << sol.duplicateNumbersXOR(nums) << "\n";

    return 0;
}
