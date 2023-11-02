#include <iostream>
using namespace std;

struct NodeInfo {
    int nodes;
    int sum;
    int count;
    NodeInfo(int nodes,int sum, int count):nodes(nodes),sum(sum),count(count){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(0), left(left), right(right){}
};

NodeInfo* getAverageOfSubtree(TreeNode *root){
    if(root==nullptr)return new NodeInfo(0,0,0);

    NodeInfo* left = getAverageOfSubtree(root->left);
    NodeInfo* right = getAverageOfSubtree(root->right);
    
    int nodes = left->nodes + right->nodes + 1;
    int sum = left->sum + right->sum + root->val;
    int count = left->count + right->count + (sum/nodes==root->val?1:0);

    return new NodeInfo(nodes,sum,count);
}
