class Solution {
public:
    
    bool isvalid(int assume,int n,vector<vector<int>>& statements){
        
        for(int i=0;i<n;i++){
            
            if((assume&(1<<i))==0)continue;//if i is a liar dont listen to it.
            
            for(int j=0;j<n;j++){
                
                if(statements[i][j]==2)continue;
                
                else if(statements[i][j]==1&&((assume&(1<<j))==0) ||statements[i][j]==0&&(assume&(1<<j)))
                    return false;
            }
            
            
        }
        
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0,n=statements.size(),bits=(1<<n)-1;
        
        for(int i=1;i<=bits;i++)
        {
            if(isvalid(i,n,statements))
            {
                int count=0,temp=i;
                
                while(temp!=0)
                {
                    count+=(temp&1);
                    temp>>=1;
                }
                    
                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};