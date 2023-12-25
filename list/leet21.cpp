#include"ListNode.h"
#include<vector>
#include<queue>
#include<functional>
using namespace std;
//
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    // nullhead->next = head;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            cur->next = list1;//通过cur指针，->改变节点
            list1 = list1->next;
        }else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;//移动指针
    }
    if(list1 != nullptr)cur->next = list1;
    if(list2 != nullptr)cur->next = list2;
    return dummy->next;
}
int main(){
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(1);
    ListNode* e = new ListNode(3);
    ListNode* f = new ListNode(4);
    a->next = b;
    b->next = c;
    d->next = e;
    e->next = f;
    mergeTwoLists(a,d);
}