
class Solution {
public:
    int guessNumber(int n) {
        int first = 1, last = n;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == -1)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return -1;
    }
};