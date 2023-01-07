class Solution {
public:
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
   vector<int>ans;
    stack<TreeNode*>a,b;
    
    while(root1||root2|| !a.empty()||!b.empty())
    {
        while(root1!=NULL)
        {
            a.push(root1);
            root1=root1->left;
        }
        while(root2!=NULL)
        {
            b.push(root2);
            root2=root2->left;
        }
        if(b.empty()||(!a.empty() &&a.top()->val<=b.top()->val))
        {
            root1=a.top();
            a.pop();
            ans.push_back(root1->val);
            root1=root1->right;
        }
        else
        {
            root2=b.top();
            b.pop();
            ans.push_back(root2->val);
            root2=root2->right;
        }
    }
    return ans;
}
};