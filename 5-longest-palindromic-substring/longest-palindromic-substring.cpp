class Solution {
public:
    string longestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLen = 0, endPos = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    int l = dp[i][j];
                    int startInS = i - l;
                    int startInRev = n - j;
                    if (startInS == startInRev && l > maxLen) {
                        maxLen = l;
                        endPos = i;
                    }
                }
            }
        }

        return s.substr(endPos - maxLen, maxLen);
    }
};