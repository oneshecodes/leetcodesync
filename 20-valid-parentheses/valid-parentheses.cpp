class Solution {
public:
    bool isValid(string s) {
        // Use a stack to keep track of the opening brackets.
        std::stack<char> st;
        
        for (char ch : s) {
            // Push opening brackets onto the stack.
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // For closing brackets, check if the stack is empty.
                if (st.empty()) return false;
                
                // Pop the top element from the stack.
                char top = st.top();
                st.pop();
                
                // Check if the type of the closing bracket matches.
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // If the stack is empty, all opening brackets have been matched.
        return st.empty();
    }
};
