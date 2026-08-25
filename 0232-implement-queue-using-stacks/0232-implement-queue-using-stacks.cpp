// class MyQueue {
// private:
//   stack<int> st1, st2;
// public:
//     MyQueue() {
        
//     }
    
//     void push(int x)  // push takes time = O(2*n)
//     {
//      while(!st1.empty())
//         {
//             st2.push(st1.top());
//             st1.pop();
//         }

//         st1.push(x);

//         while(!st2.empty())
//         {
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
    
//     int pop() {
//         int top = st1.top();
//         st1.pop();
//         return top;
//     }
    
//     int peek() {
//         return st1.top();
//     }
    
//     bool empty() {
//         return st1.empty();
//     }
// };

// Reducing push time thus leading to inc in time of other operations
class MyQueue {
private:
  stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x)  // push takes time = O(2*n)
    {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty())
        {
           int el = st2.top();
           st2.pop();
           return el;
        }
        else{
            while(st1.size()){
            st2.push(st1.top());
            st1.pop();}

            int el = st2.top();
            st2.pop();
            return el;
        }
    }
    
    int peek() {
          if(!st2.empty())
        {
            return st2.top();
        }
        else{
            while(st1.size()){
            st2.push(st1.top());
            st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return (st2.empty() && st1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */