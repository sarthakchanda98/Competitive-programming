class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int temp;
        int last;
        int ogsize = nums.size();
        int i;
        int k = 0;
        for( i = 0;i<nums.size();i++)
        {
            last = nums.size()-1;
            if(nums[i] == val)
            {
                k++;
                temp = nums[i];
                nums[i] = nums[last];
                nums[last] = temp;
                if(nums[i] == nums[last])
                {
                    i--;
                }
                nums.pop_back();
            }
        }
        return ogsize - k;
    }
};
//this uses nums.pop_back function.
