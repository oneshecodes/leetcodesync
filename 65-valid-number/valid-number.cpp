class Solution {
public:
    bool isNumber(string s) {
        // Trim leading and trailing spaces
    int start = s.find_first_not_of(" \t\n\r");
    int end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos) return false;
    s = s.substr(start, end - start + 1);

    bool seenDigit = false;
    bool seenDot = false;
    bool seenExp = false;
    bool digitAfterExp = true;

    for (size_t i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            seenDigit = true;
            if (seenExp) digitAfterExp = true;

        } else if (ch == '+' || ch == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }

        } else if (ch == '.') {
            if (seenDot || seenExp) {
                return false;
            }
            seenDot = true;

        } else if (ch == 'e' || ch == 'E') {
            if (seenExp || !seenDigit) {
                return false;
            }
            seenExp = true;
            digitAfterExp = false;

        } else {
            return false;
        }
    }

    return seenDigit && digitAfterExp;
    }
};