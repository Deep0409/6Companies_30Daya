class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size(),l = 0,r = n - 1;
        
        while(l<n-1 && nums[l]<=nums[l+1]) l++; //removing the sorted part of starting
        while(r>0   && nums[r]>=nums[r-1]) r--;//removing the sorted part of last
        
        if(l>= r)return 0;
        
        int mini = nums[l],maxi= nums[r];
        
        for(int i = l; i <= r; i++)  //finding smaller and larger element 
        {
            maxi =maxi>nums[i]?maxi:nums[i];
            mini =mini>nums[i]?nums[i]:mini; 
        }
        
        while(r<n &&nums[r]<maxi)r++;   //finding position of smaller and larger element
        while(l>=0&&nums[l]>mini)l--;
        
        return r - l - 1;
        
    }
};
