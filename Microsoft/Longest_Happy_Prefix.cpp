class Solution {
public:
    string longestPrefix(string s) {
        string ans="";
        int i=0, j=1,n=s.size();
        vector<int>lps(n, 0);
    
        while(j<n){
            
            if(s[i]==s[j])
                lps[j++]=(i++)+1;
                
            else if(i)
                i=lps[i-1];
            
            else
                j++;
        
        }
        
        ans=s.substr(0,lps[n-1]);
        
        return ans;
    }
};