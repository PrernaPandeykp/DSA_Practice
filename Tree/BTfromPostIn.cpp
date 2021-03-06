/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* postIn(vector<int>& inorder,int is,int ie, vector<int>&postorder, int ps, int pe,map<int,int>&hm){
        if(is>ie || ps>pe) return NULL;
        
        TreeNode * root= new TreeNode(postorder[pe]);
        
        int locIn = hm[postorder[pe]];
        int numsleft= locIn - is;
    
        root->left= postIn(inorder,is, locIn-1,postorder,ps,ps+numsleft-1,hm);
        root->right=postIn(inorder,locIn+1,ie,postorder,ps+numsleft,pe-1,hm);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.size()!= postorder.size()) return NULL;
        map<int,int> hm;
        for(int i=0;i<inorder.size();i++) hm[inorder[i]]=i;
        
        return postIn(inorder,0,inorder.size()-1 ,postorder,0,postorder.size()-1,hm);
        
    }
};