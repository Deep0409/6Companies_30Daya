class Solution {
public:
   int rev(int n){
        int rev_n = 0;
        while (n > 0) {
            rev_n = rev_n* 10 + n % 10;
            n = n / 10;
        }
        return rev_n;
    }
    
    int countNicePairs(vector<int>& nums) {
       unordered_map<int, int> m;
    int ans = 0;
    for (int i : nums)
        ans = (ans + m[i- rev(i)]++) % 1000000007;
    return ans;
    }
};