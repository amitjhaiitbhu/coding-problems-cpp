#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluateExpression(const std::string& expression) {
    std::stack<int> values;
    std::stack<char> ops;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            int num = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                ++i;
            }
            values.push(num);
            --i; // Move back to the last digit
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    std::string expression1 = "3 + 4 * 2 - 6 / 3";
    std::cout << "Result 1: " << evaluateExpression(expression1) << std::endl;

    std::string expression2 = "8 - 3 * 2 + 6 / 2";
    std::cout << "Result 2: " << evaluateExpression(expression2) << std::endl;

    std::string expression3 = "10 - 6 / 3";
    std::cout << "Result 3: " << evaluateExpression(expression3) << std::endl;

    return 0;
}
