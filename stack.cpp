// Question 1
/*#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int data;
    Node* next;


    Node(int val) : data(val), next(nullptr){}
};

class EvaluatePostfix{
    private:
        Node* top;

        void push(int digit){
            Node* newNode = new Node(digit);
            newNode->next = top;
            top = newNode;
        }

        void pop(){
            if(top==nullptr)
                return;
            else{
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

    public:
        EvaluatePostfix() : top(nullptr){}

        int returnTop(){
            if(top!=nullptr)
                return top->data;

            else
                return 0;
        }

        void evaluatepostfix(){
            string exp;
            cout << "Enter the expression: ";
            getline(cin,exp);
            for(int i=0; i<exp.length(); i++){
                if(exp[i]==' ')
                    continue;

                else if(isdigit(exp[i])){
                    int num = 0;
                    while (isdigit(exp[i])) {
                        num = num * 10 + (int)(exp[i] - '0');
                        i++;
                    }
                    i--;
                    this->push(num);
                }

                else{
                    int num1 = this->returnTop();
                    this->pop();
                    int num2 = this->returnTop();
                    this->pop();

                    switch(exp[i]){
                        case '+':
                            this->push(num2+num1);
                            break;

                        case '-':
                            this->push(num2-num1);
                            break;

                        case '*':
                            this->push(num2*num1);
                            break;

                        case '/':
                            this->push(num2/num1);
                            break;

                        case '^':
                            this->push(pow(num2, num1));

                        default:
                            break;
                    }
                }
            }
        }
};

int main(){
    EvaluatePostfix stack;
    stack.evaluatepostfix();
    cout << stack.returnTop() << endl;
    return 0;
} */

// Question 2

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
