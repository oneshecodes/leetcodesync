class Solution{
public:
    vector<int> countBits(int n){
        vector<int> ans = {
            0, 1, 
            1, 2
        };

        if(n <= 3)  return std::vector<int>(ans.begin(), ans.begin()+n+1);

        // for n > 3, follow this pattern
        int read = 2; // index
        int prev_bin_digits = 2;
        int rewind_units = 0;
        bool copying = true;
        for(int count = 4; count <= n; count++){
            if(copying){
                ans.push_back(ans[read]);
                if(ans[read] != prev_bin_digits){
                    read++;
                    rewind_units++;
                }
                else{
                    copying = false;
                    read -= rewind_units;
                    rewind_units = 0;
                }
            }
            else{
                ans.push_back(ans[read]+1);
                if(ans[read] == prev_bin_digits){
                    copying = true;
                    prev_bin_digits++;
                }
                read++;
            }
        }
        return ans;
    }   
};