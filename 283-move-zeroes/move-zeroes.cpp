class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        for (int i = 0, j = 1; i < n && j < n;) {
            if (a[i] == 0 && a[j] != 0) {
                swap(a[i], a[j]);
                i++;
                j++;
            }
            else if (a[i] == 0 && a[j] == 0) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }
    }
};