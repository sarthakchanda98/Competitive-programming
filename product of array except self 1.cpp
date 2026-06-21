// O(n) TC and O(n) SC
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> product;
        int prefix =1,suffix =1;
        vector<int> left;
        vector<int> right;
        left.push_back(prefix);
        right.push_back(suffix);
        //calculate prefix
        for(int i = 1;i<nums.size();i++)
        {
            left.push_back(left[i-1]*nums[i-1]);
        }
        //calculate suffix
        for(int i = nums.size()-2;i>=0;i--)
        {
            right.push_back(right[nums.size()-i-2]*nums[i+1]);
        }
        //calculate product
        for(int i = 0;i<left.size();i++)
        {
            product.push_back(left[i]*right[nums.size()-i-1]);
        }
        return product;
    }
};
