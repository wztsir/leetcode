#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
#include"TreeNode.h"
using namespace std;
class FindElements {
private:
    unordered_set<int> tree;
public:
    void dfs(TreeNode* root, int x){
        if(root == nullptr)return;
        tree.insert(x);
        dfs(root->left, 2 * x + 1);
        dfs(root->right, 2 * x + 2);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root, 0);
    }
    
    bool find(int target) {
        return tree.find(target) != tree.end();
    }
};
int main()
{
   system("pause");
   return 0;
}
