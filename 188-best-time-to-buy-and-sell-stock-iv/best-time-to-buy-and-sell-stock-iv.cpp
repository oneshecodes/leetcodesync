class Solution {
private:
    int solve(int ind,int trans,int k,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size() || trans==2*k){
            return 0;
        }
            
        if(dp[ind][trans]!=-1){
            return dp[ind][trans];
        }
            
        int profit=0;
        if(trans%2==0){
            profit=max(-prices[ind]+solve(ind+1,trans+1,k,prices,dp),solve(ind+1,trans,k,prices,dp));
        }
        else{
            profit=max(prices[ind]+solve(ind+1,trans+1,k,prices,dp),solve(ind+1,trans,k,prices,dp));
        }
            
        return dp[ind][trans]=profit;
    }        
public:
    int maxProfit(int k, vector<int>& prices) {

        // 1.memoization
        // int n=prices.size();
        // int size=2*k;
        // vector<vector<int>>dp(n+1,vector<int>(size,-1));
        // int profit=solve(0,0,k,prices,dp);
        // return profit;
            
        // 2.Tabulations
        // int n=prices.size();
        // int size=2*k;
        // vector<vector<int>>dp(n+1,vector<int>(size+1,0));
            
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int trans=size-1;trans>=0;trans--){
        //         int profit=0;
        //         if(trans%2==0){
        //             profit=max(-prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
        //         }
        //         else{
        //             profit=max(prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
        //         }
                    
        //         dp[ind][trans]=profit;
        //     }
        // }
            
        // return dp[0][0];
                    
            int n=prices.size();
            int size=2*k;
            vector<int> next(size+1,0);
            vector<int> curr(size+1,0);
            
            for(int ind=n-1;ind>=0;ind--){
                for(int trans=size-1;trans>=0;trans--){
                    int profit=0;
                    if(trans%2==0){
                        profit=max(-prices[ind]+next[trans+1],next[trans]);
                    }
                    else{
                        profit=max(prices[ind]+next[trans+1],next[trans]);
                    }
                    
                    curr[trans]=profit;
                }
                next=curr;
            }
            
            return next[0];
                 
    }
};