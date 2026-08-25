class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        bool num = false;
        int highest = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]==k)
            {
                num = true;
                break;
            }
        }
        if(!num)
        return k;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]%k==0)
            {
                if(nums[i]>highest)
                {
                    highest = nums[i];
                }
            }
        }
        sort(nums.begin(),nums.end());
        bool missing = false;
        bool flag;
        int smallest=101;
        for(int i = highest;i>=k;i-=k)
        {
            int start=0;
            int end=nums.size()-1;
            int mid;
            flag = false;
            while(start<=end)
            {
                mid = start + (end-start)/2;
                if(nums[mid]==i)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid]>i)
                {
                    end = mid-1;
                }
                else if(nums[mid]<i)
                {
                    start = mid+1;
                }
            }
            if(!flag)
            {   
                missing = true;
                if(i<smallest)
                {
                smallest = i;
                }
            }
        }
        return (missing)?smallest:highest+k;
    }
};