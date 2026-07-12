class Solution {
public:
    void sortColors(vector<int>& A) 
    {
        //dutch national flag algo
        int low = 0;
        int mid = 0;
        int high = A.size()-1;
        int temp;
        while(mid<=high)
        {
            if(A[mid]==0)
            {
                temp = A[mid];
                A[mid] = A[low];
                A[low] = temp;
                low++;
                mid++;
            }
            else if(A[mid] == 1)
            {
                mid++;
            }
            else if(A[mid]==2)
            {
                temp = A[mid];
                A[mid] = A[high];
                A[high] = temp;
                high--;
            }
        }
    }
};