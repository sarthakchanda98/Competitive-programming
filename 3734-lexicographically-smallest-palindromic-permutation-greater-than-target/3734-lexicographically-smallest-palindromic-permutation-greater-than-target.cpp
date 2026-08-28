class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        int half = n / 2;

        // Remove the characters needed to make target's left half.
        for (int i = 0; i < half; i++) {
            cnt[target[i] - 'a'] -= 2;
        }

        // If target's left half cannot be formed, we'll backtrack.
        auto valid = [&]() {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < 0)
                    return false;
            }
            return true;
        };

        // First check whether target itself can be formed
        // as a palindrome and is strictly greater on the right half.
        if (valid()) {
            string left = target.substr(0, half);
            string right = left;

            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += char('a' + mid);

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        // Backtrack from the rightmost position of the left half.
        for (int i = half - 1; i >= 0; i--) {
            int current = target[i] - 'a';

            // Restore the pair corresponding to target[i].
            cnt[current] += 2;

            if (!valid())
                continue;

            // Try the smallest character greater than target[i].
            for (int j = current + 1; j < 26; j++) {
                if (cnt[j] < 2)
                    continue;

                cnt[j] -= 2;

                string left = target.substr(0, i);
                left += char('a' + j);

                // Fill remaining left half with smallest characters.
                for (int c = 0; c < 26; c++) {
                    for (int x = 0; x < cnt[c] / 2; x++) {
                        left += char('a' + c);
                    }
                }

                string ans = left;

                if (n % 2)
                    ans += char('a' + mid);

                string right = left;
                reverse(right.begin(), right.end());

                ans += right;

                return ans;
            }
        }

        return "";
    }
};
