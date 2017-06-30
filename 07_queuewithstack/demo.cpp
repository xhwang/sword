
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
      pushStack = stack<int>();
      popStack = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int rel = peek();
      popStack.pop();
      return rel;
    }
    
    /** Get the front element. */
    int peek() {
        
      int rel;
      if(!popStack.empty()) {
        rel = popStack.top();
      }
      else {
        transfer();
        rel = popStack.top();
      }

      return rel;
    }

    void transfer() {
        while(!pushStack.empty()) {
          int t = pushStack.top();
          pushStack.pop();
          popStack.push(t);
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      return pushStack.empty() && popStack.empty();
    }

private:
    stack<int> pushStack;
    stack<int> popStack;
};


int main() {
  /**
   * Your MyQueue object will be instantiated and called as such:
   */
  MyQueue obj = MyQueue();

  obj.push(1);
  obj.push(2);

  int param_2 = obj.pop();
  int param_3 = obj.peek();
  bool param_4 = obj.empty();

  cout<<param_2<<param_3<<param_4<<endl;
}
