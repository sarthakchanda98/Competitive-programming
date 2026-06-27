#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int max_len = 0;
        
        if (count.count(1)) {
            max_len = (count[1] % 2 != 0) ? count[1] : count[1] - 1;
        }
        
        for (auto& [x, _] : count) {
            if (x == 1) continue;
            
            int current_len = 0;
            long long current_base = x;
            
            while (count.count(current_base) && count[current_base] >= 2) {
                current_len += 2;
                current_base *= current_base;
            }
            
            if (count.count(current_base) && count[current_base] == 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};
