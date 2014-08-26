#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q);

int main()
{
    TreeNode root(0);
    root.left = new TreeNode(1);
    root.right = new TreeNode(2);
    root.left->left = new TreeNode(3);
    root.left->right = new TreeNode(6);
    root.left->left->left = new TreeNode(4);
    root.left->left->right = new TreeNode(5);

    cout << isSameTree(&root, &root) << endl;
    return 0;
}

//recursive: 4ms
bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (p != NULL)
	{
		if (q != NULL)
		{
			return (p->val == q->val) && isSameTree(p->left, q->left) \
				&& isSameTree(p->right, q->right);
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (q != NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

