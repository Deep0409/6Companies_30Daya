class Solution {
public:
  void mergesort(vector<int>&sub,int l,int r,int diff,long long &count){
   
    if(l<r)
    {   
        int m = (l+r)/2;
        mergesort(sub,l  ,m ,diff,count);
        mergesort(sub,m+1,r ,diff,count);
            merge(sub,l,  m ,r   ,diff,count);
    }   
  
}
    long long merge(vector<int>&sub,int l,int m,int r,int diff,  long long &count){
    vector <int> temp (r-l+1);
    int ll,rr,idx=-1;
    
    for(int i=l;i<=m;i++)
    {
       ll = m+1,rr=r,idx=-1;
       
        while(ll<=rr){
            
            int mid = ll+(rr-ll)/2;
            
            if(sub[mid]>=sub[i]-diff){
                idx = mid;
                rr = mid-1;
            }else{
                ll = mid+1;
            }
        }
        if(idx!=-1)count+= (r-idx+1);
    }    
    
    int i=l,j=m+1,k=0;
    
    while(i<=m and j<=r){
        
        if(sub[i]<=sub[j]){
            temp[k++]=sub[i++];
        }else{
            temp[k++]=sub[j++];
        }
    }
    
    while(i<=m)temp[k++]=sub[i++];
    while(j<=r)temp[k++]=sub[j++];
    for(int i=l;i<=r;i++)sub[i]=temp[i-l];
        
        
    return count;
}


long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    
    
    int n = nums1.size();
    long long count=0;
    vector <int>sub(n);
    for(int i=0;i<n;i++)sub[i] = nums1[i]-nums2[i];
    mergesort(sub,0,n-1,diff,count);
    return count;
    
}
};