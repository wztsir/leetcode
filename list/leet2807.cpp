#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include"ListNode.h"
#include<functional>
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;
    ListNode* node = head;
    while(node != nullptr && node->next != nullptr){
        int t = gcd(node->val, node->next->val);
        ListNode* add = new ListNode(t);
        add->next = node->next;
        node->next = add;
        node = add->next;
    }
    return head;
}
int main()
{
   system("pause");
   return 0;
}
