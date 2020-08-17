/* refer
https://www.cnblogs.com/anniekim/archive/2013/06/15/morristraversal.html   morris
https://segmentfault.com/a/1190000016674584    
*/
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
                    pre->right = root;
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
        vector<int> nodes;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root){
                nodes.push_back(root->val);
                st.push(root);
                root = root->left;
            }else{
                root = st.top();
                st.pop();
                root = root->right;
            }       
        }
        return nodes;
    }
};

class PostTreeTraversal{
public:
    vector<int> dfsTraversal(TreeNode* root){
        vector<int> nodes;
        dfs(nodes, root);
    }
    void dfs(vector<int>& nodes, TreeNode* root){
        if(!root) return;
        dfs(nodes, root->left);
        dfs(nodes, root->right);
        nodes.push_back(root->val);
    }

    vector<int> iterativePost(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode* > st;
        TreeNode* pre = NULL;

        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if(root->right == NULL || root->right == pre){
                nodes.push_back(root->val);
                st.pop();
                pre = root;
                root = NULL;
            }else{
                root = root->right;
            }
        }
        return nodes;
    }

    void addReverse(vector<int>& nodes, TreeNode* s, TreeNode* e){
        vector<int> tmp;
        while(s){
            tmp.push_back(s->val);
            if(s == e){
                break;
            }else{
                s = s->right;
            }
        }
        nodes.insert(nodes.end(), tmp.rbegin(), tmp.rend());
    }

    vector<int> morrisPost(TreeNode* root){
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        TreeNode* pre = NULL;
        vector<int> nodes;
        root = dummy;
        while(root){
            if(root->left == NULL){
                root = root->right;
            }else{
                pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = root;
                    root = root->left;
                }else{
                    addReverse(nodes, root->left, pre);
                    pre->right = NULL;
                    root = root->right;
                }
            }
        }
        return nodes;
    }
};