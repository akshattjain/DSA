#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *next;
    Node(char val) : data(val), next(nullptr) {}
};
class InfixtoPostfix
{
private:
    Node *top;
    void push(int digit)
    {
        Node *newNode = new Node(digit);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top == nullptr)
            return;
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    char returnTop()
    {
        if (top != nullptr)
            return top->data;
        else
            return ' ';
    }

public:
    InfixtoPostfix() : top(nullptr) {}
    void infixtopostfix()
    {
        string exp;
        cout << "Enter the expression: ";
        getline(cin, exp);
        string result;
        for (int i = 0; i < exp.length(); i++)
        {
            char c = exp[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                result += c;
            else if (c == '(')
                push('(');
            else if (c == ')')
            {
                while (returnTop() != '(')
                {
                    result += returnTop();
                    pop();
                }
                pop();
            }
            else
            {
                while (top != nullptr && prec(exp[i]) <= prec(returnTop()))
                {
                    result += returnTop();
                    pop();
                }
                push(c);
            }
        }
        while (top != nullptr)
        {
            result += returnTop();
            pop();
        }
        cout << result << endl;
    }
};
int main()
{
    InfixtoPostfix stack;
    stack.infixtopostfix();
    return 0;
}