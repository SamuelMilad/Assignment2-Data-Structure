#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class TreeNode
{
public:
    char data;
    TreeNode *left, *right;

    TreeNode(char data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class StackNode
{
public:
    TreeNode *treeNode;
    StackNode *next;

    StackNode(TreeNode *treeNode)
    {
        this->treeNode = treeNode;
        next = nullptr;
    }
};

class ExpressionTree
{
private:
    StackNode *top;
public:
    ExpressionTree()
    {
        top = nullptr;
    }

    void push(TreeNode *n)
    {
        if (top == nullptr)
            top = new StackNode(n);
        else
        {
            StackNode *node = new StackNode(n);
            node->next = top;
            top = node;
        }
    }
    TreeNode *pop()
    {
        if (top == nullptr)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            TreeNode *ptr = top->treeNode;
            top = top->next;
            return ptr;
        }
    }
    TreeNode *peek()
    {
        return top->treeNode;
    }
    void insert(char ch)
    {
        if (isDigit(ch))
        {
            TreeNode *node = new TreeNode(ch);
            push(node);
        }
        else if (isOperator(ch))
        {
            TreeNode *node = new TreeNode(ch);
            node->left = pop();
            node->right = pop();
            push(node);
        }
        else
        {
            cout<<"Invalid Expression"<<endl;
            return;
        }
    }
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    int toDigit(char ch)
    {
        return ch - '0';
    }
    void buildTree(string s)
    {
        for (int i =s.length()-1; i >=0; i--)
            insert(s[i]);
    }
    double evaluate()
    {
        return evaluate(peek());
    }
    double evaluate(TreeNode *ptr)
    {
        if (ptr->left == nullptr && ptr->right == nullptr)
            return toDigit(ptr->data);
        else
        {
            double result = 0.0;
            double left = evaluate(ptr->left);
            double right = evaluate(ptr->right);
            char op = ptr->data;
            switch (op)
            {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                default:
                    result = left + right;
                    break;
            }
            return result;
        }
    }
    void infix()
    {
        inOrder(peek());
    }
    void inOrder(TreeNode *ptr)
    {
        if (ptr != nullptr)
        {
            inOrder(ptr->left);
            cout<<ptr->data;
            inOrder(ptr->right);
        }
    }
};
int main()
{
    cout<<"Test case1: +3*4/82"<<endl;
    ExpressionTree et1;
    et1.buildTree("+3*4/82");
    cout<<"Infix : ";
    et1.infix();
    cout<<endl<<"Evaluated Result : "<<et1.evaluate()<<endl;

    cout<<endl<<"Test case2: /*6+123"<<endl;
    ExpressionTree et2;
    et2.buildTree("/*6+123");
    cout<<"Infix : ";
    et2.infix();
    cout<<endl<<"Evaluated Result : "<<et2.evaluate()<<endl;

    cout<<endl<<"Test case3: ++8/*1426"<<endl;
    ExpressionTree et3;
    et3.buildTree("++8/*1426");
    cout<<"Infix : ";
    et3.infix();
    cout<<endl<<"Evaluated Result : "<<et3.evaluate()<<endl;

    cout<<endl<<"Test case4: +5*5/55"<<endl;
    ExpressionTree et4;
    et4.buildTree("+5*5/55");
    cout<<"Infix : ";
    et4.infix();
    cout<<endl<<"Evaluated Result : "<<et4.evaluate()<<endl;

    cout<<endl<<"Test case5: +5*99"<<endl;
    ExpressionTree et5;
    et5.buildTree("+5*99");
    cout<<"Infix : ";
    et5.infix();
    cout<<endl<<"Evaluated Result : "<<et5.evaluate();
    return 0;
}