#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SubTreeInfo{
    public:
    int min;
    int max;
    int ans;
    SubTreeInfo(int min=INT_MAX,int max=INT_MIN, int ans=0):min(min),max(max),ans(ans){}
};

SubTreeInfo* getSubTreeInfo(TreeNode* root){
    if(root==nullptr){
        return new SubTreeInfo();
    }
    else if (root->left==nullptr && root->right==nullptr){
        return new SubTreeInfo(root->val,root->val,0);
    }
    SubTreeInfo *left = getSubTreeInfo(root->left); SubTreeInfo *right = getSubTreeInfo(root->right);
    int minima = min(left->min,right->min); int maxima = max(left->max,right->max);
    int ans = max(abs(root->val-minima),abs(root->val-maxima));
    if(root->left)ans = max(ans,left->ans);
    if(root->right)ans = max(ans,right->ans);
    if(root->left==nullptr){
        minima = right->min;
        maxima = right->max;
    }
    else if(root->right==nullptr){
        minima = left->min;
        maxima = left->max;
    }
    SubTreeInfo *newInfo = new SubTreeInfo(min(minima,root->val),max(maxima,root->val),ans);
    return newInfo;
}

int maxAncestorDiff(TreeNode* root) {
    return getSubTreeInfo(root)->ans;       
}

int main()
{
}