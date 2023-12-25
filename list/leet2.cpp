#include"ListNode.h"
#include<vector>
#include<queue>
#include<functional>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    int k = 0;//进位
    while(l1 != nullptr || l2 != nullptr){
        int a = l1 != nullptr ? l1->val : 0;
        int b = l2 != nullptr ? l2->val : 0;
        int num = (a + b + k)%10;
        k = (a + b + k)/10;
        if(l1)l1 = l1->next;
        if(l2)l2 = l2->next;
        ListNode* temp = new ListNode(num);
        cur->next = temp;
        cur = cur->next;
    }
    if(k){
        ListNode* temp = new ListNode(k);
        cur->next = temp;
    }
    return dummy->next;
}