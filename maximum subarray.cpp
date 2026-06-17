#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,j;
        int currsum = 0;
        int maxsum = INT_MIN;
        for(i=0;i<nums.size();i++)
        {
            currsum += nums[i];
            maxsum = max(maxsum,currsum);
            if(currsum<0)
            {
                currsum = 0;
            }
        }
        return maxsum;
    }
};
