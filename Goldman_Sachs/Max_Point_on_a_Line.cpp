class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1,temp,n=points.size();
        double val;
      
        for(int i=0;i<n-1;i++){
            
            unordered_map<double,int> m;
            
            for(int j=i+1;j<n;j++){
               //calculating the slope 
                val = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                //check if slope is infinite
                if(points[j][1]-points[i][1]<0 &&(points[j][0]-points[i][0])==0 ) 
                m[abs(val)]++; 
                else
                 m[val]++;
            }
          
        
            for(auto i:m)
                ans= max(ans, i.second+1);   
        }
        return ans;
    }
};