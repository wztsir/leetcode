#include"Node.h"
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
//只深度复制从a->b，没有深度复制b->a
//[[2,4],[1,3],[2,4],[1,3]]对于节点4，没被访问，但是已经克隆过，必须先保存，不然会存在两份
//即vis没有作用

//细节，需要保证每个节点只放入q一次，保证每个节点只创造一次
Node* cloneGraph(Node* node) {
    if(node == nullptr)return node;
    unordered_set<Node*> vis;
    unordered_map<int, Node*> ma;
    queue<Node*> q,p;
    q.push(node);
    Node *root = new Node(node->val);
    p.push(root);
    // ma[root->val] = root;
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        Node* mu = p.front();
        p.pop();
        vis.insert(cur);
        ma[mu->val] = mu;
        for(int i =0; i < cur->neighbors.size(); ++i){
            Node* temp;
            if(ma.find(cur->neighbors[i]->val) != ma.end())temp = ma[cur->neighbors[i]->val];
            else {
                temp = new Node(cur->neighbors[i]->val); 
                ma[temp->val] = temp;
                q.push(cur->neighbors[i]);
                p.push(temp);
            }
            if(vis.count(cur->neighbors[i]) == 0){//写错，如果该点已经被创建就直接放入队列，但不是没被访问，没被访问，可能存在很多次放入

            }
            mu->neighbors.push_back(temp);
        }
    }
    return root;
}