#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root);
int dfs(TreeNode *root);

int main()
{
    TreeNode root(0);
    root.left = new TreeNode(1);
    root.right = new TreeNode(2);
    root.left->left = new TreeNode(3);
    root.left->right = new TreeNode(6);
    root.left->left->left = new TreeNode(4);
    root.left->left->right = new TreeNode(5);

    cout << maxDepth(&root) << endl;
    cout << dfs(&root) << endl;
    return 0;
}

int maxDepth(TreeNode *root)
{//recursive: 20ms
    if (root == NULL)
    {
        return 0;
    }

    int lmax = maxDepth(root->left);
    int rmax = maxDepth(root->right);
    if (lmax > rmax)
    {
        return lmax + 1;
    }
    else
    {
        return rmax + 1;
    }
}

int dfs(TreeNode *root)
{//stack dfs: 44ms...
    int depth = 1;

    //dfs
    stack<TreeNode *> s;
    root->val = 1;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *p = s.top();
        s.pop();
        //cout << p->val << endl;
        int d = p->val;
        if (p->left != NULL)
        {
            if (p->right != NULL)
            {
                p->right->val = p->val + 1;
                s.push(p->right);
            }
            p->left->val = p->val + 1;
            s.push(p->left);
            if (d + 1 > depth)
            {
                depth = d + 1;
            }
        }
        else if (p->right != NULL)
        {
            p->right->val = p->val + 1;
            s.push(p->right);
            if (d + 1 > depth)
            {
                depth = d + 1;
            }
        }
    }

    return depth;
}

