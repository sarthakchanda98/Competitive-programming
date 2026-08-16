class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> temp(m+n, 0);
        int counter = 0;
        if(n==0)
        {
            return;
        }
        for(int i = 0;i<=m+n-1;i++)
        {
            if(m==0)
            {
                temp[i] = nums2[i];
            }
            else
            {
            if(i<m)
            {
                temp[i] = nums1[i];
            }
            else
            {
                temp[i] = nums2[i-m];
            }
            }
        }
        sort(temp.begin(),temp.end());
        for(int x : temp)
        {
            nums1[counter] = x;
            counter++;
        }
    }
};