#include <iostream>
#include <stdlib.h>
using namespace std;

struct studentRecord
{
    int rollnumber;
    float gpa;
    studentRecord *next;
    studentRecord *prev;

};

void insert(studentRecord **head)
{
    studentRecord *ptr = (studentRecord *)malloc(sizeof(studentRecord));
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        studentRecord *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = ptr;
    }
}

void search(studentRecord **head)
{
    int toSearch;
    cout << "Enter student's rollnumber: ";
    cin >> toSearch;
   
    studentRecord * curr = * head;
    while (curr != NULL)
    {
        if (curr -> rollnumber == toSearch)
        {
            cout << "Roll Number: " << curr -> rollnumber << endl;
            cout << "GPA: " << curr -> gpa << endl;
            break;
        }
        else
        {
            curr = curr -> next;
        }
    }
}

void print(studentRecord **head){
    studentRecord * curr = * head;
    while (curr != NULL)
    {
        cout << "Roll Number: " << curr -> rollnumber << endl;
        cout << "GPA: " << curr -> gpa << endl;
        cout << "" << endl;
        curr = curr -> next;
    }
}

void deletee(studentRecord **head){
int toDelete;
    cout << "Enter student's rollnumber to delete it: ";
    cin >> toDelete;
   
    studentRecord *curr=*head;
 

   if(toDelete==(*head)->rollnumber){
    *head=(*head)->next;
    free(curr);
}else{
studentRecord*prev=*head;
curr=(*head)->next;
while(curr!=NULL){
if(curr->rollnumber==toDelete){
prev ->next=curr->next;
free(curr);
break;
}
curr=curr->next;
prev=prev->next;
}

}
}

void deleteall(studentRecord **head){
studentRecord* curr = *head;
while((*head) != NULL) {
    curr = (*head);
    *head = (*head)->next;
    free(curr);
  }

  cout<<"All data are deleted successfully " <<endl;
}
int main()
{
    studentRecord *head = NULL;
    int select = 1;
    cout << "Press 1 to insert"<< endl;
    cout << "Press 2 to search"<< endl;
    cout << "Press 3 to print"<< endl;
    cout << "Press 4 to delete"<< endl;
    cout << "Press 5 to delete all"<< endl;
    cout << "Press 0 to exit"<< endl;
    cout << "Enter your choice: " << "" ;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            insert(&head);
        }
        if (select == 2)
        {
            search(&head);
        }
        if (select == 3)
        {
            print(&head);
        }
        if (select == 4)
        {
            deletee(&head);
        }
        if (select == 5)
        {
            deleteall(&head);
        }
    cout << "Enter your choice again: " << "";
    cin >> select;
    }
   
}

