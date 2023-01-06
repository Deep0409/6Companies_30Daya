#include<string.h>
class Solution {
public:
    string getHint(string secret, string guess) {
       int n=secret.size();
        int countc=0,countb=0;
        map<int,int> mp1,mp2;
        
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                countb++;
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
            
        }
        
        for(auto i:mp1)
        {
            if(mp2.find(i.first)!=mp2.end())
            countc+=min(mp2[i.first],i.second);
        }
        string ans="";
        ans=to_string(countb)+"A"+to_string(countc)+"B";
        return ans;
    }
};