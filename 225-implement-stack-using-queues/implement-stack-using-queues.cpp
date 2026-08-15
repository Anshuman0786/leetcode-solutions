class MyStack {
public:
    queue<int> qt;

    void push(int x) {
        qt.push(x);
        int n = qt.size();
        while (n-- > 1) {
            qt.push(qt.front());
            qt.pop();
        }
    }

    int pop() {
        int val = qt.front();
        qt.pop();
        return val;
    }

    int top() {
        return qt.front();
    }

    bool empty() {
        return qt.empty();
    }
};