class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // Shift by 1 to make it 0-indexed
            result = char('A' + (columnNumber % 26)) + result;
            columnNumber /= 26;
        }
        return result;
    }
};
