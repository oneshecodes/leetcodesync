class Solution {
public:

    void recursion(vector<vector<int>> &res, vector<int> &sum, vector<int> cand, int target, int start){
        if(target <= 0){
            if(target == 0) res.push_back(sum);
            return;
        }
        for (int i = start; i < cand.size(); i++){
            sum.push_back(cand[i]);
            recursion(res, sum, cand, target-cand[i], i);
            sum.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> sum;
        int start = 0;
        recursion(res, sum, candidates, target, start);
        return res;
    }
};