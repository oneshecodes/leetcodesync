class MyQueue {
public:
    // approach 1(out of 2): push O(n), pop O(1)
    stack <int> s1, s2;

    MyQueue() {}

    void push(int x) {
        // #1: s1 -> s2
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // #2: x -> s1
        s1.push(x);

        // #3: s2 -> s1
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();

        }
    }
    
    int pop() {
        int value = s1.top();
        s1.pop();
        return value;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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