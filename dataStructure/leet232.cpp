// #include <stack>

// class MyQueue {
// private:
//     std::stack<int> inStack;
//     std::stack<int> outStack;

// public:
//     MyQueue() {

//     }
    
//     void push(int x) {
//         inStack.push(x); // 将元素压入进队栈
//     }
    
//     int pop() {
//         if (outStack.empty()) {
//             // 如果出队栈为空，将进队栈的元素依次弹出并压入出队栈
//             while (!inStack.empty()) {
//                 outStack.push(inStack.top());
//                 inStack.pop();
//             }
//         }
        
//         // 弹出出队栈的栈顶元素，即为队列的头部元素
//         int front = outStack.top();
//         outStack.pop();
        
//         return front;
//     }
    
//     int peek() {
//         if (outStack.empty()) {
//             // 如果出队栈为空，将进队栈的元素依次弹出并压入出队栈
//             while (!inStack.empty()) {
//                 outStack.push(inStack.top());
//                 inStack.pop();
//             }
//         }
        
//         // 返回出队栈的栈顶元素，即为队列的头部元素
//         return outStack.top();
//     }
    
//     bool empty() {
//         // 队列为空的条件是进队栈和出队栈都为空
//         return inStack.empty() && outStack.empty();
//     }
// };

#include<stack>
using namespace std;
class MyQueue {
private:
    stack<int> inLine;
    stack<int> outLine;
public:
    MyQueue() {

    }
    
    void push(int x) {
        inLine.push(x);
    }
    
    int pop() {
        if(outLine.empty()){
            int temp;
            while(!inLine.empty()){
                temp = inLine.top();
                inLine.pop();
                outLine.push(temp);
            }
        }
        int front = outLine.top();
        outLine.pop();
        return front;
    }
    
    int peek() {
        if(outLine.empty()){
            int temp;
            while(!inLine.empty()){
                temp = inLine.top();
                inLine.pop();
                outLine.push(temp);
            }
        }
        return outLine.top();
    }
    
    bool empty() {
        return inLine.empty() && outLine.empty();
    }
};

