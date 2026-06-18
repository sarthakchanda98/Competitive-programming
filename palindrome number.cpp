#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        long checker = 0;
        int digit;
        long copy = x;
        if(x<0)
        {
            return false;
        }
        while(copy!=0)
        {
            checker = (checker*10) + (copy%10);
            copy/=10;
        }
        if(checker == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

