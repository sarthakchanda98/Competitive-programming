class Solution {
public: 
    long long countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int i;
        int score = 0;
        long long ans = 0;
        
        vector<int> count(2 * n + 1, 0);
        int smaller_scores = 0;
        
        for(i = 0; i < n; i++)
        {
            count[score + n]++;
            
            if(nums[i] == target)
            {
                score++;
                smaller_scores += count[score - 1 + n];
            }
            else
            {
                score--;
                smaller_scores -= count[score + n];
            }
            
            ans += smaller_scores;
        }
        return ans;
    }
};
