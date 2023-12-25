#include"ListNode.h"
using namespace std;

//一看就会，一写就废
//还是没有理解关键点
//局部：关键点是当前节点，不是去转换前一个箭头，而是后一个箭头
//整体：递归写法，是后序，天然的从后往前处理

//迭代的写法，是利用指针处理前一个箭头
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}
//其实存在的是思维误区，while的初始情况是将head的next置为空，而不是将第二个节点指向head
ListNode* reverseList2(ListNode* head) {
    if(head == nullptr)return head;
    ListNode* nxt = head;
    ListNode* pre = nullptr;
    while(head != nullptr){
       nxt = head->next;
       head->next = pre;
       pre = head;
       head = nxt; 
    }
    return pre;
}