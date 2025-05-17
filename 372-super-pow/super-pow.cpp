class Solution {
public:
    int binaryPow(int a, int p) {
        int res = 1;
        int base = a % 1337;
        while (p) {
            if (p & 1) {
                res *= base;
                res %= 1337;
            }
            base *= base;
            base %= 1337;
            p >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (a % 1337 < 2) {
            return a % 1337;
        }
        int residues7[] = {7, 49, 343, 1064, 763, 1330, 1288, 994, 273, 574};
        int residues191[] = {191, 382, 764};
        int n = b.size();
        int p = 0, p7 = 0, p191 = 0;
        for (int i = 0; i < n; i++) {
            p *= 10;
            p7 *= 10;
            p191 *= 10;
            p += b[i];
            p7 += b[i];
            p191 += b[i];
            p %= 1140;
            p7 %= 10;
            p191 %= 3;
        }
        p7 = p7 - 1 < 0 ? 9 : p7 - 1;
        p191 = p191 - 1 < 0 ? 2 : p191 - 1;
        if (a % 7 == 0) {
            return residues7[p7] * binaryPow(a / 7, p) % 1337;
        }
        if (a % 191 == 0) {
            return residues191[p191] * binaryPow(a / 191, p) % 1337;
        }
        return binaryPow(a, p) % 1337;
    }
};