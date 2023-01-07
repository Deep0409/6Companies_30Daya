#include"bits/stdc++.h"
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdd = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < numsDivide.size(); ++i)
            gcdd =gcd(numsDivide[i],gcdd);
            
        for (int i = 0; i < nums.size(); i++)
            if (!(gcdd % nums[i])) 
                return i;
        
        return -1;
    }
};