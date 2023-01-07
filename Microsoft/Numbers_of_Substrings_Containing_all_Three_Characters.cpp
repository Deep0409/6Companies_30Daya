class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0, j=0;
        unordered_map<int,int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]-'a']++;
            while(mp[0] && mp[1] && mp[2]){
                ans+=s.size()-i;
                mp[s[j]-'a']--;
                j++;
            }
        }
        return ans;
    }
};