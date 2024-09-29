#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int element) {
    // Base case: if the stack is empty, push the element
    if (s.empty()) {
        s.push(element);
        return;
    }

    // Step 1: Remove the top element
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively call to insert the element at the bottom
    insertAtBottom(s, element);

    // Step 3: Push the top element back on the stack
    s.push(topElement);
}

void reverseStack(std::stack<int>& s) {
    // Base case: if the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Step 1: Remove the top element
    int topElement = s.top();
    s.pop();

    // Step 2: Reverse the remaining stack
    reverseStack(s);

    // Step 3: Insert the removed element at the bottom of the reversed stack
    insertAtBottom(s, topElement);
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;

    // Push elements onto the stack
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    std::cout << "Original Stack: ";
    printStack(s);

    // Reverse the stack
    reverseStack(s);

    std::cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
