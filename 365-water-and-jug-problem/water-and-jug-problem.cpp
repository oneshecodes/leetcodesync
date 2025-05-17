class Solution {
public:
//   DIE HARD PROBLEM!!


// //  WAY-1:DFS



//    bool dfs(int x,int y,int target,int sum1,vector<int>&vis,int sum){
//     if(sum>sum1 || sum<0 || vis[sum]==1){
//         return false;
//     }
//      vis[sum]=1;

//     if(sum==target)
//     return true;
    
//     int filj1=dfs(x,y,target,sum1,vis,sum+x);
//     int empj1=dfs(x,y,target,sum1,vis,sum-x);
//     int filj2=dfs(x,y,target,sum1,vis,sum+y);
//     int empj2=dfs(x,y,target,sum1,vis,sum-y);

//     return (filj1||empj1||filj2||empj2);

//    }
//     bool canMeasureWater(int x, int y, int target) {
//        int sum1=x+y;
//        vector<int>vis(sum1+1,0);
//        return dfs(x,y,target,sum1,vis,0);

//     }};






// //WAY-2:BFS


// bool canMeasureWater(int x, int y, int target) {
    
//     if(target>x+y)
//     return false;
//     int sum=x+y;
//     vector<int>vis(sum+1,0);
//     vis[0]=1;
//     queue<int>pq;
//     pq.push(0);
//     int ar[]={x,-x,y,-y};
//     while(!pq.empty()){
//         int x1=pq.front();
//         pq.pop();
//         if(x1==target){
//             return true;
//         }
        

//         for(int i=0;i<4;i++){
//             int br=x1+ar[i];
        

//         if( br>=0 && br<=sum && !vis[br]){
//              vis[br]=1;
//              pq.push(br);
             
//         }

//     }
//     }

// return false;
// }};




 // WAY-3:MATHEMATICAL


 bool canMeasureWater(int x, int y, int target) {
    
      int sum=x+y;
      return (target<=sum && (target%__gcd(x,y)==0));
    }
};

