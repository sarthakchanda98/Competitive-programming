#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums)
    {
        vector<int> duplicates;
        int res;
        bool flag = false;
        
        // Loop through vector to find duplicates
        for(size_t i = 0; i < nums.size(); i++)
        {
            for(size_t j = i + 1; j < nums.size(); j++)
            {
                if(nums.at(j) == nums.at(i))
                {
                    duplicates.push_back(nums.at(i));
                    flag = true;
                }
            }
        }
        
        if(!flag) return 0;

        res = duplicates[0];
        for(size_t i = 1; i < duplicates.size(); i++)
        {
            res ^= duplicates.at(i);
        }
        return res;
    }
};

int main() {
    Solution solver;
    vector<int> nums;
    int temp;

    cout << "=== Duplicate Numbers XOR Calculator ===" << endl;
    cout << "Enter integers separated by spaces or newlines." << endl;
    cout << "Enter any character (like 'q') to stop and calculate." << endl;
    cout << "--------------------------------------------------" << endl;

    // cin >> temp returns false if input is not an integer
    while (cin >> temp) {
        nums.push_back(temp);
    }

    if (nums.empty()) {
        cout << "No valid numbers entered." << endl;
    } else {
        cout << "\nCalculating..." << endl;
        int result = solver.duplicateNumbersXOR(nums);
        cout << "The XOR of duplicate numbers is: " << result << endl;
    }

    return 0;
}
