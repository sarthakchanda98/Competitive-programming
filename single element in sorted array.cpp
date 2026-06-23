class Solution {
public:
    int singleNonDuplicate(vector<int>& A) 
    {
        int start =0;
        int end = A.size()-1;
        int mid;
        if(A.size() == 1)
        {
            return A[0];
        }
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(mid == 0)
            {
                if(A[mid] != A[mid+1])
                {
                    return A[mid];
                }
            }
            if(mid == A.size()-1)
            {
                if(A[mid] == A[mid-1])
                {
                    return A[mid];
                }
            }
            if(A[mid]!=A[mid-1] && A[mid] != A[mid+1])
            {
                return A[mid];
            }
            else if(mid%2==0)
            {
                if(A[mid] == A[mid-1])
                {
                    end = mid-1;
                }
                else if(A[mid]==A[mid+1])
                {
                    start = mid+1;
                }
            }
            else if(mid%2!=0)
            {
                if(A[mid]==A[mid-1])
                {
                    start = mid+1;
                }
                else if(A[mid]==A[mid+1])
                {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
