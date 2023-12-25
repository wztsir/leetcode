#include"Node.h"
#include<queue>
using namespace std;
Node* connect(Node* root) {
    if(root==nullptr)return nullptr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sq = q.size();
        for(int i = 0; i < sq; ++i){
            Node* cur = q.front();
            q.pop();
            if(i == sq-1)cur->next = nullptr;
            else cur->next = q.front();//犯低级错误，队列有出，但是没有进入
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
    }
    return root;
}