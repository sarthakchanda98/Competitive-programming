class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int minfreq = floor(nums.size()/3);
        vector<int> result;
        sort(nums.begin(),nums.end());
        int freq = 1;
        int ans = nums[0];
        if(freq > minfreq)
            {
                result.push_back(ans);
            }
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                freq++;
            }
            else
            {
                freq = 1;
                ans = nums[i];
            }
           if(freq > minfreq)
            {
                if((find(result.begin(),result.end(),ans)==result.end()))
                result.push_back(ans);
            }
        }
        return result;
    }
};
