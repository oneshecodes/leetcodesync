class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int one = 2, two = 1; // ways to reach step n-1 and n-2
        for (int i = 3; i <= n; ++i) {
            int temp = one + two;
            two = one;
            one = temp;
        }
        return one;
    }
};
