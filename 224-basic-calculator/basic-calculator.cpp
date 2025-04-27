class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, num = 0, sign = 1;
        for (char c : s) {
            if (isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '+') { res += sign * num; num = 0; sign = 1; }
            else if (c == '-') { res += sign * num; num = 0; sign = -1; }
            else if (c == '(') { st.push(res); st.push(sign); res = 0; sign = 1; }
            else if (c == ')') {
                res += sign * num;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
                num = 0;
            }
        }
        return res + sign * num;
    }
};
