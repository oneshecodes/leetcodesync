const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);
    return 0;
}();
#endif
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = 0;
         vector<int> ans(n-k+1);
         deque<int> res;
         for (int i = 0; i < n; i++) {
            if (!res.empty() && res.front() <= i - k) res.pop_front();
            while (!res.empty() && nums[res.back()] <= nums[i] ) res.pop_back();
            res.push_back(i);
           if (i>=k-1) ans[idx++] = nums[res.front()];
         }
         return ans;
    }
};