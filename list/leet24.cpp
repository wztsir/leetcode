#include"ListNode.h"
#include<vector>
#include<queue>
#include<functional>
using namespace std;
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;
    ListNode* next = swapPairs(head->next->next);
    head->next->next = head;
    ListNode* res = head->next;
    head->next = next;
    return res;
}