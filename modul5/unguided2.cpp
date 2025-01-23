#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix)
{
    stack<char> operatorStack;
    string prefix;

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    for (char &ch : infix)
    {
        if (isalnum(ch))
        {
            prefix += ch;
        }
        else if (ch == ')')
        {
            operatorStack.push(ch);
        }
        else if (ch == '(')
        {
            while (!operatorStack.empty() && operatorStack.top() != ')')
            {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the closing bracket
        }
        else if (isOperator(ch))
        {
            while (!operatorStack.empty() && precedence(operatorStack.top()) > precedence(ch))
            {
                prefix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop the remaining operators from the stack
    while (!operatorStack.empty())
    {
        prefix += operatorStack.top();
        operatorStack.pop();
    }

    // Reverse the result to get the final prefix expression
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

string infixToPostfix(string infix)
{
    stack<char> operatorStack;
    string postfix;

    for (char &ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            operatorStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the opening bracket
        }
        else if (isOperator(ch))
        {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(ch))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    // Pop the remaining operators from the stack
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main()
{
    string infix = "A*(B+C)/D^E-F";
    cout << "Infix Expression: " << infix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
