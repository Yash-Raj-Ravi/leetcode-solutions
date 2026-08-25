// 1.Using 1 queue
// class MyStack {

// private:
//        queue<int> q;
// public:
//     MyStack() {
  
//     }
    
//     void push(int x) {
//         int sz = q.size();
//         q.push(x);
//         for(int i=0; i<sz; i++)
//         {
//             q.push(q.front());
//             q.pop();
//         } 
//     }
    
//     int pop() {
//         int top = q.front();
//         q.pop();
//         return top;
//     }
    
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.size()==0;
//     }
// };

// 2.Using 2 queues
class MyStack {

private:
    queue<int> q1, q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};





/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */