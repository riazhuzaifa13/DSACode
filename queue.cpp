#include <iostream>
#include <stdlib.h>
using namespace std;

struct stNode
{
    int rollnumber;
    stNode*Next;
};
void enqueue(stNode**Front, stNode**Rear)


{
     stNode*ptr=(stNode*)malloc(sizeof(stNode));
     cout << "Insert Roll Number: ";
     cin >> ptr->rollnumber;
   
     ptr->Next = NULL;
     if (*Front==NULL && *Rear==NULL)
     {
         *Front= *Rear=ptr;
       
     }
     else
     {
        stNode*curr=*Rear;
        *Rear = ptr;
        curr->Next=*Rear;
       
     }
 }

void dequeue(stNode**Front, stNode**Rear)
{
stNode*curr=*Front;
if(curr != NULL)
    {
       *Front = (*Front)->Next;
        free(curr);
       
    }
    else
    {
        cout << "QueueisUnderflow"<< endl;
    }
}

void print(stNode** Front, stNode** Rear)
{
    stNode* curr = *Front;
    while (curr != NULL)
    {
        cout << "Roll Number: " << curr->rollnumber << endl;
        cout << "" << endl;
        curr = curr->Next;
    }
}


int main()
{
    stNode* Front = NULL;
    stNode* Rear = NULL;
    cout << "List is currently empty" << endl;
    enqueue(&Front, &Rear);
    cout << "Press 1 to enqueue"<< endl;
    cout << "Press 2 to dequeue"<< endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    int select = 1;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            enqueue(&Front, &Rear);
        }
        if (select == 2)
        {
            dequeue(&Front, &Rear);
        }
        if (select == 3)
        {
            print(&Front, &Rear);
        }
        cout << "Enter your choice again: "<< "";
        cin >> select;
    }
}

