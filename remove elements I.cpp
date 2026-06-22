// O(n) solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int place = nums.size()-1;
        int temp;
        int ogsize = nums.size();
        int i;
        int k = 0;
        for( i = 0;i<=place;i++)
        {
            if(nums[i] == val)
            {
                k++;
                temp = nums[i];
                nums[i] = nums[place];
                nums[place] = temp;
                if(nums[i]==nums[place])
                {
                    i--;
                }
                place--;
            }
        }
        return ogsize - k;
    }
};
