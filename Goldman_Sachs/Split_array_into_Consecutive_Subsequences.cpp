class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m,last_end;
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        
        for(int i=0;i<n;i++){
            
            if(m[nums[i]]<=0)continue;
            
            if(last_end[nums[i]-1]>0){
               last_end[nums[i]-1]--;
                m[nums[i]]--;
                last_end[nums[i]]++;
            }
            
            else if(m[nums[i]+1] and m[nums[i]+2]){
                m[nums[i]]--;
                m[nums[i]+1]--;
                m[nums[i]+2]--;
                last_end[nums[i]+2]++;
            }
            
            else return false;
        }
        return true;
    }
};