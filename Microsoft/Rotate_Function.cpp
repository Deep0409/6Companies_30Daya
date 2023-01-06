#include<vector.h>

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {


        /*f[1]-f[0]=sum-n*nums[n-i]
        wherei=1,2,3,...
        */
    int sum=0,f0=0,n=nums.size();

      for(int i=0;i<n;i++)
      {
          sum+=nums[i];
          f0+=i*nums[i];

      }  

      int ans=f0;
      for(int i=n-1;i>0;i--)
      {
          ans=max(ans,f0+sum-(n*nums[i]));
          f0=f0+sum-(n*nums[i]);

      }

      return ans;

/*2nd Method (Sliding Window)

    int sum = 0, f0 = 0;
        int len = A.size();
        for(int i=0;i<len;i++) {
            sum += A[i];
            f0 += (i * A[i]);
        }

        int  l = 1, r;
        int newfn = f0;
        
        while(l < len) {
            r = l + len - 1;
            
            int remove = (l-1) * A[l-1];
            int add    = r * A[r%len];
            
            newfn= newfn - remove + add - sum;
            
            f0 = max(f0, newfn);
            
            l++;
        }
        
        return f0;
*/

      }



      };