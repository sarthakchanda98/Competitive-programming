class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        if(arr.size() == 1)
        {
            return 1;
        }
        int temp;
        sort(arr.begin(),arr.end());
        if(arr[0] != 1)
        {
            arr[0] = 1;
        }
        for(int i = 1; i<arr.size();i++)
        {
            if(abs(arr[i]-arr[i-1] <= 1))
            continue;
            else
            {
                arr[i] = arr[i-1] + 1;
            }
        }

        //highest value
        int highest = arr[0];
        for(int i = 1;i<arr.size();i++)
        {
            highest = max(highest,arr[i]);
        }
        return highest;


    }
};
