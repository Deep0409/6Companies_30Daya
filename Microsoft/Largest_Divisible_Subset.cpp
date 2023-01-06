
//Here the Time Complexity is O(n^2)=O(nlogn)(for sorting)+O(n^2)(for traversing)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums;
        
        vector<pair<int,int>>num;
        vector<int>par(n+1);
        int ind=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
           
            num.push_back({nums[i],0});
            
        }
     
        par[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            par[i]=-1;
            for(int j=0;j<i;j++){
                
                if(num[i].first%num[j].first==0)
                {
                    
                    if(num[j].second+1>num[i].second)
                    {
                        num[i].second=num[j].second+1;
                        par[i]=j;
                        ind=num[ind].second>num[i].second?ind:i;
                    }
                    
                }
            }
        }
        
     if(ind==-1)return{nums[0]};
        
        
        vector<int>ans;
        while(ind>=0)
        {
            ans.push_back(nums[ind]);
            ind=par[ind];
        }
        
        return ans;
    }
};


/*
here the time Complexity is exponential
class Solution {
    
    vector<int> ans;

    void solve(vector<int>nums, int curr, int prev, vector<int> res,vector<int>&ans)
    {
        if(curr==nums.size()) 
        {
            if(res.size()>ans.size()) ans = res;
            return;
        }
        
        solve(nums,curr+1,prev,res); 
        
        if(prev == -1 || nums[curr]%nums[prev]==0)
        {
            res.push_back(nums[curr]);
            solve(nums,curr+1,curr,res); // take
        }
        
    }
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans={};
        sort(nums.begin(),nums.end());
        solve(nums,0,-1,{},ans);
        return ans;
    }
};

*/