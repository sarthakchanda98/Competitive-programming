class Solution {
public:
    double myPow(double x, int n) {
        long binary = n;
        if(n<0)
        {
            binary = -(binary);
        }
        double ans = 1;
        if(x==1)
        {
            return 1;
        }
        if(n == 0)
        {
            return 1;
        }
        if(n>=0)
        {
        while(binary>0)
        {
            if(binary%2==1)
            {
                ans = ans * x;
            }
            x *=x;
            binary /= 2;
        }
        }
        else
        {
            while(binary>0)
            {
                if(binary%2==1)
            {
                ans = ans * (1/x);
            }
            x *=x;
            binary /= 2;
            }
        }
        return ans;
    }
};
