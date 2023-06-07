#include <iostream>
#include <string.h>
using namespace std;
int static coun3 = 0;
class Stack
{
    char s[50];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(char val)
    {
        if (!isFull())
        {
            top++;
            s[top] = val;
        }
        else
            cout << "The Stack is Full \n";
    }
    char pop()
    {
        char val = '\0';
        if (!isEmpty())
        {
            val = s[top];
            top--;
        }
        else
            cout << "The Stack is Empty \n";
        return val;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if (top == 49)
            return 1;
        else
            return 0;
    }
    char Display() {
        if (top >= 0) {
            cout<< "\nStack elements are: ";
            for (int i = 0; i <= top ; i++){
               cout<< s[i] ;
            }
            cout<< "\n";
       }
        else
           cout<< "\nStack elements are: /";
    }
        char Reverse() {
          if (top >= 0) {
            for (int i = 0; i <= coun3 ; i++)
                {
                  pop();
                }
       }
       // else
       //     return '/';
    }

   /* void display() {
        if (top >= 0) {
            cout<< "Stack elements are:";
            for (int i = top; i >= 0; i--)
               cout<< s[i] << "  ";
       }
        else
           cout<< "Stack is empty";
    }*/
};
class str
{
    char inputstr[50], revstr[50];
    Stack ob;

public:
    void readstring()
    {
        cout << "\nEnter String \n";
        cin >> inputstr;
        cout << "You Entered -> " << inputstr << "\n";
    }

    void convertstring()
    {
        int i;
        int coun1 = 0, coun2 = 0;
        for (i = 0; inputstr[i] != '\0'; i++)
        {
            if (inputstr[i]=='/' )
            {
                 ob.push(inputstr[i]);
                 coun1++;
            }


            else if (inputstr[i] == '.')
            {
                coun2++;
            }
            else if (inputstr[i] != '.' && inputstr[i] != '\0' && inputstr[i] != '/')
            {
                ob.push(inputstr[i]);
                coun3++;
            }
            if(coun1 %2 ==0 )
            {
                ob.pop();
            }
            if (coun2 >1)
            {
                ob.Reverse();
                coun2=0;
            }
            if(coun1==2)
            {
                coun3=1;
            }
        }
        ob.Display();
    }

};
int main()
{
    str obj;
    obj.readstring();
    obj.convertstring();
    return 0;
}








/* void revstring()
    {
        int i;
        char ch;
        for(i=0;ob.display() !='\0'; i++)
        {
            ob.push(ob.display());
        }
        i=0;
        cout << "\n\nAfter reverse your string -> ";
        while(!ob.isEmpty())
        {
            ch=ob.pop();
            cout << ch;
            revstr[i]=ch;
            i++;
        }
        cout << "\n";
    }
}*/

  /*  void revstring()
    {
        int i;
        char ch;
        for(i=0;ob.display() !='\0'; i++)
        {
            ob.push(ob.display());
        }
        i=0;
        cout << "\n\nAfter reverse your string -> ";
        while(!ob.isEmpty())
        {
            ch=ob.pop();
            cout << ch;
            revstr[i]=ch;
            i++;
        }
        cout << "\n";
    }*/





                /*if(inputstr[i]>=97 && inputstr[i]<=122)
            {
                tempstr[j]= inputstr[i];
                j++;
            }
            else if(inputstr[i]>=65 && inputstr[i<=90])
            {
                tempstr[j]=inputstr[i]+32;
                j++;
            }*/
        //}
        //tempstr[j] = '\0';
        //strcpy(inputstr,tempstr);
        //cout << "\n\nYour converted string -> "<<inputstr<<"\n";


   /* void check()
    {
        cout << "\n\n";
        cout <<"*******************************************************************\n";
        cout<< "\nCheck \n";
        readstring();
        convertstring();
        for(int i=0; i<49; i++)
        {
            revstr[i]=0;
        }
        revstring();

        if(strcmp(inputstr,revstr)==0)
            cout<< "\nyour string is \n";
        else
            cout<< "\nyour string is not \n";

    }*/
