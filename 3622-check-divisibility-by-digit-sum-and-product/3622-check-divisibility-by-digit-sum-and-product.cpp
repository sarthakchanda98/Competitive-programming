class Solution {
public:
    bool checkDivisibility(int n)
    {
        long sum = 0;
        long prod = 1;
        int copyn = n;
        int copy2n = n;
        while(copyn!=0)
        {
            sum += copyn%10;
            copyn/=10;
        }
        while(copy2n!=0)
        {
            prod*= copy2n%10;
            copy2n/=10;
        }

        if(n%(sum+prod)==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};