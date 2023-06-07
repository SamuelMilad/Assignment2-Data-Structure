#include <iostream>
#include <queue>
using namespace std;
class stack
{
private:
    queue<int> Q;
public:
    int top()
    {
        return Q.front();
    }

    void push(int x)
    {
        int size=Q.size();
        Q.push(x);
        for(int i=0;i<size;i++)
        {
            Q.push(Q.front());
             Q.pop();
        }
    }

    void pop()
    {
        Q.pop();
    }
};
int main() {
    stack S;
    S.push(7);
    S.push(10);
    S.push(15);
    cout<<S.top()<<endl;
    S.pop();
    cout<<S.top();
    return 0;
}
