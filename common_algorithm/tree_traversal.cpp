
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x) {}
};

class InorderTraversal{
public:
    // 递归
    vector<int> dfsInorder(TreeNode* root) {
        vector<int> nodes;
        dfs(nodes, root);
        return nodes;
    }
    void dfs(vector<int>& nodes, TreeNode* root){
        if(!root) return;
        dfs(nodes, root->left);
        nodes.push_back(root->val);
        dfs(nodes, root->left);
    }

    // 遍历
    vector<int> iterativeInorder(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
    
    // morris
    vector<int> morrisInorder(TreeNode* root){
        vector<int> nodes;
        while(root){
            if(root->left){
                TreeNode *pre = root->left;
                while(pre && pre->right != root){
                    pre = pre->right;

                }
                if(!pre->right){
                pre->right = root;
                root = root->left;
                }else{
                pre->right = NULL;
                nodes.push_back(root->val);
                root = root->right;
                }
            }else{
                nodes.push_back(root->val);
                root = root->right;
            }
        }
    }
};

class PreorderTraversal{
public:
    vector<int> morrisPreorder(TreeNode* root){
        vector<int> nodes;
        while(root){
            if(!root->left){
                nodes.push_back(root->val);
                root = root->right;
            }else{
                TreeNode *pre = root->left;
                while(pre->right &&  pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    nodes.push_back(root->val);
                    root = root->left;
                }else{
                    pre->right = NULL;
                    root = root->right;
                }
            }
        }
        return nodes;
    }

    vector<int> dfsPreOrder(TreeNode* root){
        vector<int> nodes;
        dfs(nodes, root);
    }
    void dfs(vector<int>& nodes, TreeNode* root){
        if(!root) return;
        nodes.push_back(root->val);
        dfs(nodes, root->left);
        dfs(nodes, root->right);
    }

    vector<int> iterativePreOrder(TreeNode* root){
        
    }
};


