// O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int sum;
        vector<int> result;
        vector<int> index;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int start = 0;
        int end = copy.size()-1;
        while(start<end)
        {
            sum = copy[start] + copy[end];
            if(sum>target)
            {
                end--;
            }
            else if(sum<target)
            {
                start++;
            }
            else
            {
                result.push_back(copy[start]);
                result.push_back(copy[end]);
                break;
            }
        }
        if(result[0]==result[1])
        {
            auto it1 = find(nums.begin(),nums.end(), result[0]);
            index.push_back(it1-nums.begin());
            auto it2 = find(it1+1, nums.end(), result[0]);
            index.push_back(it2-nums.begin());
        }
        else
        {
            for(int i : result)
            {
                auto it1 = find(nums.begin(),nums.end(), i);
                index.push_back(it1-nums.begin());
            }
        }
        return index;
    }
};
