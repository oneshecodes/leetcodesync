class Solution {
public:
    void Util(string& num, int target, vector<string>& ans, long temp, 
              long prevNum, int index, string s) {
        // Base case: when we reach the end of the string
        if (index == num.length()) {
            if (temp == target) {
                ans.push_back(s);
            }
            return;
        }

        // Iterate over possible numbers (avoid leading zero cases)
        for (int i = index; i < num.length(); i++) {
            string currStr = num.substr(index, i - index + 1);
            long currNum = stol(currStr);

            // Avoid numbers with leading zeros (except "0" itself)
            if (i > index && num[index] == '0') break;

            if (index == 0) {
                // First number, directly add it without an operator
                Util(num, target, ans, currNum, currNum, i + 1, currStr);
            } else {
                // Addition
                Util(num, target, ans, temp + currNum, currNum, i + 1, s + "+" + currStr);
                
                // Subtraction
                Util(num, target, ans, temp - currNum, -currNum, i + 1, s + "-" + currStr);
                
                // Multiplication (handles correct precedence)
                Util(num, target, ans, temp - prevNum + (prevNum * currNum),
                     prevNum * currNum, i + 1, s + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        Util(num, target, ans, 0, 0, 0, "");
        return ans;
    }
};