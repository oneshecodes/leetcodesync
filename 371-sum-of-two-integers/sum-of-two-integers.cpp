class Solution {
public:
    int getSum(int a, int b) {
    int x = a^b;
    int y = (a&b)<< 1;
    while (y!= 0){
        int car = (x&y) << 1;
        x = x^y;
        y = car; 
    }
     return x;   
    }
};