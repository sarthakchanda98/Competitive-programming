class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        if(nums.size()==1)
        return 1;
        int minimum=INT_MAX;
        int maximum=INT_MIN;
        int minindex;
        int maxindex;
        int d1;
        int d2;
        int d3;
        int d4;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>maximum)
            {
                maxindex = i;
                maximum = nums[i];
            }
            if(nums[i]<minimum)
            {
                minindex = i;
                minimum = nums[i];
            }
        }
        if(minindex<maxindex)
        {
            d1 = minindex+1;
            d2 = nums.size()-maxindex;
            d3 = maxindex+1;
            d4 = nums.size()-minindex;
            return min((d1+d2),(min(d3,d4)));
        }
        else
        {
            d1 = maxindex+1;
            d2 = nums.size()-minindex;
            d3 = minindex+1;
            d4 = nums.size()-maxindex;
            return min((d1+d2),(min(d3,d4)));
        }
    }
};