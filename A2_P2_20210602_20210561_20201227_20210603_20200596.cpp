#include <iostream>
using namespace std;
int static j;
int static k;
class node
{
public:
    int data;
    node* next;
    node()
    {
        data = 0;
        next = NULL;
    }
};
class Queue
{
public:
    node* Front;
    node* rear;
    Queue()
    {
        Front = rear = NULL;
    }
    bool isEmpty()
    {
        if (Front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
    void Enqueue(int new_value)
    {
        node* newnode = new node();
        newnode->data = new_value;
        if (isEmpty())
        {
            Front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
        int Dequeue()
    {
        if(isEmpty())
            cout<< "The Queue is Empty \n";
        else if(Front == rear)
        {
            delete Front;
            Front = rear = NULL;
        }
        else
        {
            int static val;
            node* delnode = Front;
            val = Front->data;
            Front = Front ->next;
            delete delnode;
            return val ;

        }
    }
   int display()
    {
    int value ;
    node* temp = Front;
      for (int l = 0; l < k; l++)
      {
        value = temp->data;
        temp = temp->next;
       }
       return value;
     }

};

int main()
{
    Queue Q1;
    cout << "Enter the number of people \n";
    cin >> j;
    int static notickets ;
    for (int i = 0; i < j; i++)
    {
        cout << "Tickets for number " << i << ":  \n";
        cin >> notickets;
        Q1.Enqueue(notickets);
    }
    cout << "Enter K from (0 to "<<j-1 <<") \n";
    cin >> k ;
    k = k+1;
    int kk= Q1.display(), Count=0;
if(k <=j)
    {
    for(int i = 1; i<= kk; i++)
        {
        if(i<kk)
            {
            for(int c=0;c<j;c++)
                {
                int nval = Q1.Dequeue();
                Q1.Enqueue(nval-1 );
                if(nval>0)
                   {
                    Count++;
                   }
                 }
               for(int c=0;c<j;c++)
                {
                Q1.Enqueue(Q1.Dequeue());
                }
            }
            else
            {
            for(int c=0;c<k;c++)
                {
                int nval = Q1.Dequeue();
                Q1.Enqueue(nval-1 );
                if(nval>0)
                {
                Count++;
                }
                }
            }
        }

                cout<< "The time needed to buy a ticket = "<< Count <<" seconds \n";
    }
else if(k>j)
    {
    cout << "Error! please Enter number between 0 , " << j << "\n";
    }

    return 0;
}
