#include <iostream>
#include <stack>

void insertSorted(std::stack<int>& stack, int value) {
    // Base case: if the stack is empty or the value is greater than the top element
    if (stack.empty() || value > stack.top()) {
        stack.push(value);
        return;
    }

    // Otherwise, remove the top element and sort the rest of the stack
    int top = stack.top();
    stack.pop();
    insertSorted(stack, value);
    
    // Push the top element back after inserting the value
    stack.push(top);
}

void sortStack(std::stack<int>& stack) {
    // Base case: if the stack is empty, return
    if (stack.empty()) {
        return;
    }

    // Remove the top element
    int top = stack.top();
    stack.pop();

    // Sort the remaining stack
    sortStack(stack);

    // Insert the removed element back into the sorted stack
    insertSorted(stack, top);
}

int main() {
    std::stack<int> stack;
    
    // Example input
    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(2);
    stack.push(5);

    std::cout << "Stack before sorting: ";
    std::stack<int> temp = stack; // Temporary stack to print
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    // Sort the stack
    sortStack(stack);

    std::cout << "Stack after sorting: ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}
