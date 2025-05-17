class Solution {
public:
    int lengthLongestPath(string input) {
        deque<int> dq;
        int len = 0, res = 0, level = 0;
        bool file = false;
        for(char c: input){
            if(c == '\n'){
                dq.push_back(len);
                level = len = file = 0;
            }
            else if(c == '\t') ++level;
            else if(c == '.') ++len, file = true;
            else{
                ++len;
                if(file) res = max(res, len + accumulate(dq.begin(), dq.end(), 0) + level);
                while(level < dq.size()){
                    dq.pop_back();
                }
            }
        }        
        return res;
    }
};