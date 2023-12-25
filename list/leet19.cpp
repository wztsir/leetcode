#include"ListNode.h"
using namespace std;
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == nullptr)return nullptr;
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *fast = dummyNode, *slow = dummyNode;
    while(n--){
        fast = fast->next;
    }
    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyNode->next;
}