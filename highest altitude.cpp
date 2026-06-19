class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        vector<int> heights;
        heights.push_back(0);
        for(int i : gain)
        {
            altitude += i;
            heights.push_back(altitude);
        }
        int maximum = heights[0];
        for(int i = 1;i<heights.size();i++)
        {
            maximum = max(maximum,heights[i]);
        }
        return maximum;
    }
};
