#include <iostream>
#include <stdlib.h>
using namespace std;

struct stNode
{
    int RN;
    stNode*Next;
};
void push(stNode**top)
{
     stNode*ptr=(stNode*)malloc(sizeof(stNode));
     cout << "Insert Roll Number: ";
     cin >> ptr->RN;

     ptr->Next = NULL;
     if (top==NULL)
     {
         *top=ptr;
     }
     else
     {
         stNode*curr=*top;
         ptr->Next=curr;
         *top=ptr;
     }
 }


void print(stNode**top)
{
    stNode*curr=*top;
    while (curr != NULL)
    {
        cout << "here's the student's roll no: " << curr->RN << endl;
        cout << "" << endl;
        curr = curr->Next;
    }
}

void pop(stNode** top)
{

stNode* curr = *top;
if (curr->Next == NULL)
{
free(curr);
cout << "List is empty now"<< endl;
}
else if(curr->Next==0){
cout << "List is empty now"<< endl;

}
else
{
*top = (*top)->Next;
free(curr);
}
}

int main()
{
    stNode* top = NULL;
    cout << "List is empty" << endl;
    push(&top);
    cout << "Press 1 to push" << endl;
    cout << "Press 2 to pop" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    int select = 1;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            push(&top);
        }
        if (select == 2)
        {
            pop(&top);
        }
        if (select == 3)
        {
            print(&top);
        }
       
        cout << "Enter again: "<< "";
        cin >> select;
    }
}

