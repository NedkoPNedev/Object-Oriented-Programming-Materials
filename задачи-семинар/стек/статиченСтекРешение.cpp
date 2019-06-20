#include <iostream>
using namespace std;

const int MAX_STACK = 100;
const int EMPTY_STACK = -1;

class Stack {
private:
    int arr[MAX_STACK];
    int top;
public:
    Stack();
    Stack(const Stack&);

    void push(int);
    int pop();
    bool isEmpty() const;
    bool isFull() const;
    void print();
};

Stack::Stack() : top(EMPTY_STACK){}

Stack::Stack(const Stack& st) {
    for (int i = 0; i <= top; i++) {
        arr[i] = st.arr[i];
    }
}

void Stack::push(int elem) {
    if (isFull()) {
        cout << "The stack is full!\n";
        return;
    }
    arr[++top] = elem;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "The stack is empty!\n";
        return -1;
    }
    return arr[top--];
}

bool Stack::isEmpty() const {
    return top == EMPTY_STACK;
}

bool Stack::isFull() const {
    return top == MAX_STACK - 1;
}

void Stack::print() {
    for (int i = top; i >= 0; i--) {
        cout << pop() << " ";
    }
    cout << endl;
}

int main() {
    Stack st;
    cout << st.pop() << endl;
    for (int i = 0; i < 10; i += 2) {
        st.push(i);
    }
    cout << st.pop() << endl;
    st.print();
    return 0;
}
