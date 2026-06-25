class Solution {
public: 
    int countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int  i,j;
        int score;
        int ans = 0;
        for(i=0;i<nums.size();i++)
        {
            score = 0;
            for(j = i;j<nums.size(); j++)
            {
                if(nums[j]==target)
                score++;
                else
                score--;
                if(score>0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
