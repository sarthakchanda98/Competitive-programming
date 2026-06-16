#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result = "";
        char c;
        for(size_t i = 0; i < s.length(); i++)
        {
            c = s.at(i);
            if(c >= 'a' && c <= 'z')
            {
                result += c;
            }
            else if(c == '#')
            {
                result += result;
            }
            else if(c == '*')
            {
                if(result.length() != 0 )
                    result.pop_back();
            }
            else if(c == '%')
            {
                int start = 0;
                int end = result.length() - 1;
                char temp;
                while(start < end)
                {
                    temp = result[start];
                    result[start] = result[end];
                    result[end] = temp;
                    start++;
                    end--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solver;
    string input;

    cout << "Enter a string to process (enter 'exit' to finish): " << endl;

    while (cin >> input) {
        if (input == "exit") {
            break;
        }

        string result = solver.processStr(input);
        cout << "Result: " << result << endl;
        cout << "\nEnter next string (or 'exit' to finish): " << endl;
    }

    return 0;
}