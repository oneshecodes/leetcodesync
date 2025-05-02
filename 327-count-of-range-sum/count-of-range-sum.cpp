#define ll long long

template<typename T>
class WaveletMatrix {
    int n, maxLog;
    vector<vector<int>> mat;
    vector<int> zs;
    vector<T> vals;
public:
    WaveletMatrix(typename vector<T>::iterator from, typename vector<T>::iterator to) {
        vector<T> temp(from, to);
        vector<T> sorted = temp;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        vals = sorted;
        vector<int> A(temp.size());
        for (size_t i = 0; i < temp.size(); i++)
            A[i] = int(lower_bound(vals.begin(), vals.end(), temp[i]) - vals.begin());
        n = int(A.size());
        int m = int(vals.size());
        maxLog = m ? 32 - __builtin_clz(m) : 1;
        mat.resize(maxLog);
        zs.resize(maxLog);
        for (int i = 0; i < maxLog; i++) {
            int bit = maxLog - 1 - i;
            mat[i].resize(n + 1);
            for (int j = 0; j < n; j++)
                mat[i][j + 1] = mat[i][j] + ((A[j] >> bit) & 1);
            zs[i] = n - mat[i][n];
            vector<int> B(n);
            int z = 0, o = zs[i];
            for (int j = 0; j < n; j++)
                B[((A[j] >> bit) & 1) ? o++ : z++] = A[j];
            A.swap(B);
        }
    }
    T kth(int l, int r, int k) {
        int res = 0;
        for (int i = 0, L = l, R = r; i < maxLog; i++) {
            int onesL = mat[i][L], onesR = mat[i][R + 1];
            int zeros = (R - L + 1) - (onesR - onesL);
            if (k < zeros) {
                int newL = L - onesL;
                L = newL;
                R = newL + zeros - 1;
            } else {
                k -= zeros;
                int newL = zs[i] + onesL;
                R = zs[i] + onesR - 1;
                L = newL;
                res |= 1 << (maxLog - 1 - i);
            }
        }
        return vals[res];
    }
    int LTE(int l, int r, T x) {
        int c = int(upper_bound(vals.begin(), vals.end(), x) - vals.begin());
        int ans = 0;
        for (int i = 0, L = l, R = r; i < maxLog; i++) {
            int onesL = mat[i][L], onesR = mat[i][R + 1];
            int zeros = (R - L + 1) - (onesR - onesL);
            if ((c >> (maxLog - 1 - i)) & 1) {
                ans += zeros;
                L = zs[i] + onesL;
                R = zs[i] + onesR - 1;
            } else {
                int newL = L - onesL;
                L = newL;
                R = newL + zeros - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll tot = 0;
        vector<ll> prefs;
        prefs.reserve(nums.size() + 1);
        prefs.push_back(tot);
        for (int x : nums) {
            tot += x;
            prefs.push_back(tot);
        }
        int cnt = 0;
        WaveletMatrix<ll> wm(prefs.begin(), prefs.end());
        for (int i = 1; i < int(prefs.size()); i++)
            cnt += wm.LTE(0, i - 1, prefs[i] - lower) - wm.LTE(0, i - 1, prefs[i] - upper - 1);
        return cnt;
    }
};