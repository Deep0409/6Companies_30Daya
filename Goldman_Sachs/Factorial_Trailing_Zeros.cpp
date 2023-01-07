class Solution {
public:
    int trailingZeroes(int n) {
        if(n<=4)
        return 0;
        int count=0,five=5;

        while(five<=n){
                count+=(n/five);
                five*=5;
        }
        return count;
    }
};