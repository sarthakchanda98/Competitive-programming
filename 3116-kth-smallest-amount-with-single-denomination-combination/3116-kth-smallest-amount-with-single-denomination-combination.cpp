class Solution {
public:
    long long gcd(long long a, long long b)
    {
        while(b)
        {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        int n = coins.size();

        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while(left < right)
        {
            long long mid = left + (right - left) / 2;

            long long count = 0;

            for(int mask = 1; mask < (1 << n); mask++)
            {
                long long multiple = 1;
                int bits = 0;

                for(int i = 0; i < n; i++)
                {
                    if(mask & (1 << i))
                    {
                        multiple = lcm(multiple, coins[i]);
                        bits++;

                        if(multiple > mid)
                            break;
                    }
                }

                if(bits % 2 == 1)
                    count += mid / multiple;
                else
                    count -= mid / multiple;
            }

            if(count >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};