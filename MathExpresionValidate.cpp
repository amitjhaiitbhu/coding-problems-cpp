#include <iostream>
#include <string>
#include <stack>
#include <cctype>

bool isExp(const char& c)
{
    return (c == '+' || c == '-');
}

bool isValidExpression(const std::string& expression) {
    std::stack<char> brackets;
    char prev = ' ';  // Initialize prev to a space character
    int i = 0;
    for (char ch : expression) {
        if((isExp(ch) && ch != '-' && i == 0)) {
            return false;
        }
        if(ch == '-' && isdigit(expression[i]))
        {
                prev = ch;
                i++;
                continue;
        }
        if(i > 0 && isExp(ch) && isExp(prev)){
            if(ch == '-' && isdigit(expression[i+1]))
            {
                prev = ch;
                i++;
                continue;
            }
            return false;
        }
        prev = ch;
        i++;
    }
    std::cout<<"value of i is "<<i<<std::endl;
    if(isExp(expression[i-1]))
        return false;
    return true;
    //return brackets.empty();  // All opening brackets should have been closed
}

int main() {
    std::string expression;
    std::cout << "Enter a mathematical expression: ";
    std::cin >> expression;

    if (isValidExpression(expression)) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Incorrect" << std::endl;
    }

    return 0;
}

