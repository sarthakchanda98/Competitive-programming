#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int num = nums[0];
        for(size_t i = 1; i < nums.size(); i++)
        {
            num = num ^ (nums.at(i));
        }
        return num;
    }
};

int main() {
    Solution solver;
    vector<int> nums;
    int temp;

    cout << "Enter numbers (enter any letter to finish): " << endl;

    while (cin >> temp) {
        nums.push_back(temp);
    }

    if (nums.empty()) {
        cout << "No elements entered." << endl;
        return 0;
    }

    int result = solver.singleNumber(nums);
    cout << "Result: " << result << endl;

    return 0;
}