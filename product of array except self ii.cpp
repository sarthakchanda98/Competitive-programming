//O(n) TC and O(1) SC
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> product(nums.size(),1);
        int prefix =1,suffix =1;
        //prefix
        for(int i = 1;i<nums.size();i++)
        {
            prefix *= nums[i-1];
            product[i] = product[i] * prefix;
        }
        //suffix
        for(int i = nums.size()-2;i>=0;i--)
        {
            suffix *= nums[i+1];
            product[i] = product[i] * suffix;
        }
        return product;
    }
};
