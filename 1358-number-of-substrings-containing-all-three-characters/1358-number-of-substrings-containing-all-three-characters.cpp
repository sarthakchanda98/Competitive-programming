#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int totalSubstrings = 0;

        for (int i = 0; i < s.length(); ++i) {
            lastSeen[s[i] - 'a'] = i;

            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
            
            totalSubstrings += (minIndex + 1);
        }

        return totalSubstrings;
    }
};