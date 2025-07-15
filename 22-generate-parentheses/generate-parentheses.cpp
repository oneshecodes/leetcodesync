class Solution {
    void f(string&s,int open,int close,int n,vector<string>&ans){
        if(s.size()==2*n){
            ans.push_back(s); 
            return; 
        }
        if(open<n){
            s.push_back('(');
            f(s,open+1,close,n,ans);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
        f(s,open,close+1,n,ans);
        s.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        f(s,0,0,n,ans);
        return ans;
        
    }
};