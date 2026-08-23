class MinStack {
public:
    /**
        s = [1, 2, 0]
        after calling pop()
        s = [1, 2]

        The visualisation is, getMin() and top() would
        return a value

        The difficulty is trying to create a getMin()
        which runs in O(1) time complexity
    **/
    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack() { // constructor, for value initialisation
    }
    
    void push(int val) {
        stack.push(val); // push current element
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val); // push the minimum top element
    }
    
    void pop() {
        stack.pop(); // pop on main stack
        minStack.pop(); // pop on extra stack
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
