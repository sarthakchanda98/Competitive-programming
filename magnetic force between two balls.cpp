class Solution {
public:
    bool isValid(vector<int> arr, int minpossible, int balls)
    {
        sort(arr.begin(),arr.end());
        int possible = 1;
        int distance = arr[0];
        for(int i = 1;i<arr.size();i++)
        {
            if((arr[i]-distance)>=minpossible)
            {
                possible++;
                distance = arr[i];
            }
            else
            {
                continue;
            }
            if(possible == balls)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m)
    {
        int minimum = 1;
        int maximum;
        int largest = INT_MIN;
        int smallest = INT_MAX;
        for(int i = 0; i<position.size();i++ )
        {
            largest = max(largest,position[i]);
            smallest = min(smallest,position[i]);
        }
        maximum = largest - smallest;
        int mid;
        int ans;
        while(minimum<=maximum)
        {
            mid = minimum + (maximum-minimum)/2;
            if(isValid(position, mid, m))
            {
                minimum = mid+1;
                ans = mid;
            }
            else
            {
                maximum = mid-1;
            }
        }
        return ans;
     }
};
