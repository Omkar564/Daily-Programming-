#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        // Check if the token is an operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;

            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                result = a / b; // Integer division
            }

            stack.push(result);
        } else {
            // Otherwise, it must be a number
            stack.push(std::stoi(token));
        }
    }

    // The final result should be the only element in the stack
    return stack.top();
}

int main() {
    std::string expression = "2 1 + 3 *";
    int result = evaluatePostfix(expression);
    std::cout << result << std::endl; // Output: 9
    return 0;
}
