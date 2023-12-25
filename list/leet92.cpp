#include"ListNode.h"
using namespace std;
//还是使用迭代的写法，反转范围内的节点
//要记住前反转区间的前两个节点，比较麻烦
// ListNode* reverseBetween(ListNode* head, int left, int right) {
//     ListNode* cur = head;
//     ListNode* pre = nullptr;
//     while(--left){
//         pre = cur;
//         cur = head->next;
//     }
//     int k  = right - left;
//     ListNode* nxt = cur;
//     while(k--){
//         nxt = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = nxt;
//     }
// }


//插入法，迭代，更简单，但要记住，要重前往后更改指向
//写法中细节：
// 1、pre固定，cur固定，就是把cur->next插入到pre与cur之间
// 2、当只有两个节点时，将后一个节点插入到虚拟节点与cur节点之间，所以虚拟节点的设置很有必要


//设置虚拟节点：
//删除节点时的边界情况： 删除节点时，如果需要删除头节点，使用 dummy 节点可以避免处理头节点的特殊情况。

//合并链表： 在合并两个有序链表时，你可以创建一个 dummy 节点作为合并后链表的头部，然后通过比较两个链表的节点值来进行合并。

//反转链表： 在反转链表时，使用 dummy 节点可以避免处理头节点的特殊情况，同时也可以帮助你建立反转后的新链表。
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *pre, *cur, *nxt, *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    pre = dummyNode;
    for(int i = 0; i < left-1; i++){
        pre = pre->next;
    }
    cur = pre->next;
    for(int i = 0; i< right-left; i++){
        nxt = cur->next;
        cur->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;  
    }
    return dummyNode->next;
}