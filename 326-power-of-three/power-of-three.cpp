/*

    Time Complexity : O(logN).

    Space Complexity : O(logN).
    
    Solved using Recursive Approach.

*/


/***************************************** Approach 1 *****************************************/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        else if(n==1){
            return true;
        }
        return n%3==0 && isPowerOfThree(n/3);  
    }
};





