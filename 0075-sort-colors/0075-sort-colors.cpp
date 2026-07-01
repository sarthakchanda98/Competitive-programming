class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int red = 0;
        int white = 0;
        int blue = 0;
        int countr = 0;
        int countw;
        int countb;
        int temp;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            red++;
            if(nums[i]==1)
            white++;
            if(nums[i]==2)
            blue++;
        }
        countw = red;
        countb = white+red;
        //place 0s
        for(int i = 0;i<nums.size();i++)
        {
            if(countr == red)
            {
                break;
            }
            if(nums[i] == 0)
            {
                temp = nums[countr];
                nums[countr] = nums[i];
                nums[i] = temp;
                countr++;
            }
        }
        // place 1s
        for(int i = red;i<nums.size();i++)
        {
            if(countw == (red+white))
            {
                break;
            }
            if(nums[i] == 1)
            {
                temp = nums[countw];
                nums[countw] = nums[i];
                nums[i] = temp;
                countw++;
            }
        }
        //2s should be automatically placed
    }
};