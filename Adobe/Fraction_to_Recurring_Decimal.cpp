class Solution {
public:
    string fractionToDecimal(int num, int den) {
        bool sign = (num<0)^(den<0) ? true: false,repeat = false;
	    long long int n =abs(num),d =abs(den);
		unordered_map<long long int, int> mp;
		string ans = "";
        
		if(sign && n!=0)
		 ans += "-";

		ans += to_string(n/d);
		n %= d;
        
		if(n==0)
			return ans;
		
		ans += ".";
	
		 
		while(n!=0 && !repeat){
            
			if(mp.find(n)==mp.end())
				mp[n] = ans.size();
            
			else if(mp.find(n)!=mp.end()){
				repeat = true; 
				ans.push_back(')');
				ans.insert(mp[n],"(");
				break;
			}
			n = n*10;
			ans += to_string(n/d);
			n %= d;
		}
		return ans;
    }
};