/* ------------------------------------------------------------------|
给你一个二叉树的根节点 root ，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径 至少包含一个 节点，且不一定经过根节点。

 

示例 1：


输入：root = [1,2,3]
输出：6
示例 2：


输入：root = [-10,9,20,null,null,15,7]
输出：42
 

提示：

树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：36 ms, 在所有 C++ 提交中击败了94.70%的用户
*	内存消耗：28.4 MB, 在所有 C++ 提交中击败了42.96%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int maxval = INT_MIN;

int dfs(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftval = max(dfs(root->left), 0);
    int rightval = max(dfs(root->right), 0);
    int sum = root->val + leftval + rightval;
    maxval = max(maxval, sum);
    return root->val + max(leftval, rightval);
}

int maxPathSum(TreeNode* root) {
    //int maxval = INT_MIN;
    dfs(root);
    return maxval;
}