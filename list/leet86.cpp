#include"ListNode.h"
using namespace std;
//不知道使用插入法，会不会更简单
ListNode* partition(ListNode* head, int x) {
    ListNode *d1 = new ListNode(-1);//小
    ListNode *d2 = new ListNode(-1);
    ListNode *c1 = d1, *c2 = d2, *c = head;
    
    while(c != nullptr){
        if(c->val  < x){
            c1->next = c;
            c = c->next;
            c1 = c1->next;
            c1->next = nullptr;//不然最后的情况下，末尾可能站粘大于等于x的节点
        }else{
            c2->next = c;
            c = c->next;
            c2 = c2->next;
            c2->next = nullptr;
        }
    }
    c1->next = d2->next;
    return d1->next;
}