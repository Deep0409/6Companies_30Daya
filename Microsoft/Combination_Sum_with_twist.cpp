class Solution {
    void dfs(int num, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if(n== 0 && k == 0) {
            ans.push_back(path);
            return;
        }
        if(n== 0 || k== 0) {
            return;
        }
        if(num > 9) return;
        
        //take it
        if(n>= num &&k > 0) {
            path.push_back(num);
            dfs(num+1, n-num,k-1, path, ans);
            path.pop_back();
        }
        
        //leave it
        dfs(num+1,n,k, path, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<vector<int>> ans;
        vector<int> path;
        dfs(1, n, k, path, ans);
        return ans;
    }
};
