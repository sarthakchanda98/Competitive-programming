class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int pivot = -1;
        for(int i = nums.size()-2; i>=0;i--)  
        {
            if(nums[i]<nums[i+1])
            {
            pivot = i;
            break;
            }
        }
        if(pivot == -1)
        {
            int start = 0;
            int end = nums.size()-1;
            int temp;
            while(start<=end)
            {
                temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
        }
        else
        {
            int temp;
            for(int i = nums.size()-1;i>pivot;i--)
            {
                if(nums[i]>nums[pivot])
                {
            temp = nums[i];
           nums[i] = nums[pivot];
           nums[pivot] = temp;
           break;
                }
            }
           int temp2;
           int start = pivot+1;
           int end = nums.size()-1;
           while(start<=end)
           {
             temp2 = nums[start];
             nums[start] = nums[end];
             nums[end] = temp2;
             start++;
             end--;
           }
        }
    }
};