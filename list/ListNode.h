#ifndef LISTNODE_H
#define LISTNODE_H

//template <typename T>
//class ListNode {
//public:
//    T value;
//    ListNode<T>* next;
//
//    ListNode(const T& val) : value(val), next(nullptr) {}
//};
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int v, ListNode* l): val(v), next(l){}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};
#endif // LISTNODE_H