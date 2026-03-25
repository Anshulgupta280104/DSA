#include <stack>
using namespace std;

class SpecialStack {
    stack<int> st1;

public:
    SpecialStack() {}

    // Push element
    void push(int x) {
        if (st1.empty()) {
            st1.push(x * 101 + x);
        } else {
            int currentMin = st1.top() % 101;
            st1.push(x * 101 + min(x, currentMin));
        }
    }

    // Pop element
    void pop() {
        if (st1.empty()) return;
        st1.pop();
    }

    // Peek (top element)
    int peek() {
        if (st1.empty()) return -1;
        return st1.top() / 101;
    }

    // Check empty
    bool isEmpty() {
        return st1.empty();
    }

    // Get minimum
    int getMin() {
        if (st1.empty()) return -1;
        return st1.top() % 101;
    }
};