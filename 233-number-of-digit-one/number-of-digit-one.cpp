class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int len = s.length() , dp[10][10];
        memset(dp , -1 , sizeof(dp));

        function<int(int,int,bool)> dfs = [&](int i , int cnt , bool is_limit)->int{
            if(i == len)return cnt;
            int& res = dp[i][cnt];
            if(!is_limit && res!=-1)return res;

            int ans = 0;
            int up = (is_limit) ? s[i]-'0' : 9;

            for(int d=0;d<=up;d++){
                ans += dfs(i+1 , cnt+(d==1) , is_limit&&(d==up));
            }
            if(!is_limit)return res = ans;

            return ans;
        };

        return dfs(0 , 0 , true);
    }
};