class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        string ans = "";

        for(int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // Try to put the same character
            if(freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Same character unavailable.
            // Find the smallest character greater than target[i].
            int j = x + 1;

            while(j < 26 && freq[j] == 0)
                j++;

            if(j < 26) {
                ans += char('a' + j);
                freq[j]--;

                // Fill remaining positions with smallest available chars
                for(int c = 0; c < 26; c++) {
                    while(freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;
                    }
                }

                return ans;
            }

            // Need to backtrack
            while(!ans.empty()) {
                int pos = ans.size() - 1;
                int prev = ans.back() - 'a';

                freq[prev]++;
                ans.pop_back();

                int j = prev + 1;

                while(j < 26 && freq[j] == 0)
                    j++;

                if(j < 26) {
                    ans += char('a' + j);
                    freq[j]--;

                    for(int c = 0; c < 26; c++) {
                        while(freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }

            return "";
        }

        // s itself equals target, so we need the next permutation.
        while(!ans.empty()) {
            int pos = ans.size() - 1;
            int prev = ans.back() - 'a';

            freq[prev]++;
            ans.pop_back();

            int j = prev + 1;

            while(j < 26 && freq[j] == 0)
                j++;

            if(j < 26) {
                ans += char('a' + j);

                freq[j]--;

                for(int c = 0; c < 26; c++) {
                    while(freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};