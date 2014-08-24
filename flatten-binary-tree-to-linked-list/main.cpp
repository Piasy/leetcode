#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root);

int main()
{
    TreeNode root(0);
    root.left = new TreeNode(1);
    root.right = new TreeNode(2);
    root.left->left = new TreeNode(3);
    root.left->right = new TreeNode(6);
    root.left->left->left = new TreeNode(4);
    root.left->left->right = new TreeNode(5);

    flatten(&root);
    TreeNode *p = &root;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->right;
    }
    return 0;
}

//recursive: 72ms
void flatten(TreeNode *root)
{//stack dfs: 68ms!
    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *p = s.top();
        s.pop();
        if (p->left != NULL)
        {
            if (p->right != NULL)
            {
                s.push(p->right);
            }
            s.push(p->left);
        }
        else if (p->right != NULL)
        {
            s.push(p->right);
        }
        p->left = NULL;
        p->right = s.empty() ? NULL : s.top();
    }
}

