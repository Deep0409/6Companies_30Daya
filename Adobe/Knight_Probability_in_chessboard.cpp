class Solution {
public:
    double prob[101][30][30];
    double knightProbability(int n, int k, int r, int c) {
        memset(prob,-1,sizeof(prob));
        return solve(n,k,r,c);
    }
    double solve(int n, int k, int r, int c){
        if(r<0 or r>=n or c<0 or c>=n)  return 0; 
        if(k==0) return 1; 
        if(prob[k][r][c]>=0) return prob[k][r][c];
        
        double ans = ( (1.0/8)*solve(n,k-1,r-2,c+1) + (1.0/8)*solve(n,k-1,r-2,c-1)+(1.0/8)*solve(n,k-1,r+2,c+1) + (1.0/8)*solve(n,k-1,r+2,c-1) + (1.0/8)*solve(n,k-1,r-1,c+2) + (1.0/8)*solve(n,k-1,r-1,c-2) + (1.0/8)*solve(n,k-1,r+1,c+2) + (1.0/8)*solve(n,k-1,r+1,c-2));  
        
        prob[k][c][r] = ans;
        
        return prob[k][r][c]=prob[k][c][r];
    }
};