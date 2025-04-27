class Solution {
public:
    int countPrimes(int n) {

        vector<bool> isPrime(n,true);
        int cnt = 0;

        for (int i =2 ; i<n ; i++){
            if(isPrime[i]){
                cnt++;
                for (int j = i*2 ; j<n ; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
        return cnt ;
    }
};