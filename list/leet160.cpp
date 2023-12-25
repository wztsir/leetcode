#include"ListNode.h"
using namespace std;
//思路也是很巧妙, 将两段链表直接拼接
//写法： 到了链表的末尾，就跳到另一个上，而不是直接拼接，写法也比较巧妙
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *h1 = headA, *h2 = headB;
    while(h1 != h2){
        if(h1==nullptr)h1 = headB;
        else h1 = h1->next;
        if(h2==nullptr)h2 = headA;
        else h2 = h2->next;
    }
    return h1; 
}