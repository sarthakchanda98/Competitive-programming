class Solution {
public:
    bool isValid(vector<int> arr, int maxSum, int div)
    {
        int sum = 0;
        int numb = 1;
        for(int i = 0; i<arr.size();i++)
        {
            if(arr[i]>maxSum)
            {
                return false;
            }
            if(sum + arr[i] <= maxSum)
            {
                sum += arr[i];
            }
            else
            {
                numb++;
                sum = arr[i];
            }
        }
        if(numb <= div)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) 
    {
       int start = nums[0];
       int end = 0;
       int ans;
       for(int i = 0; i< nums.size(); i++)
       {
           start = max(nums[i],start);
           end += nums[i];
       }
       int mid;
       while(start<=end)
       {
          mid = start + (end-start)/2;
          if(isValid(nums, mid, k))
          {
              end = mid-1;
              ans = mid;
          }
          else
          {
             start = mid+1;
          }
       }
       return ans;
    }
};

// greedy algorithm
