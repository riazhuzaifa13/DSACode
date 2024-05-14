#include <iostream>
#include <stdlib.h>
using namespace std;

void insert(int arr[] , int size) {
int key;
cout<<"Enter The Value you Want to Enter" << endl;
cin>>key;
int ind=key%size;
while(arr[ind] !=-1) {
if(ind==size) {
ind=0;
}
else{
ind++;
}
  }
arr[ind] = key
cout<<endl;

cout << "values: "<< endl;

for(int i=0; i<size;i++){
cout<<arr[i]<<endl;
}

}

void search(int arr[], int size)
{
    int value;
    cout << "Enter the value to find" << endl;
    cin >> value;
    int ind = value % size;
    int hold = ind;
    while (arr[ind] != value)
    {
        if (ind == size)
        {
            ind = 0;
        }
        else
        {
            ind++;
        }

        if (ind == hold)
        {
            cout << "Not Found " << endl;
            break;
        }
    }
    if (arr[ind] == value)
    {
        cout << "found at index " << ind << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main() {
cout << "Enter the Size of Array "<<endl;
int size;
cin>>size;
int arr[size];
for (int i=0; i<size; i++){
arr[i]=-1;
}

int a = 0;
while(a!=3) {
if(a==1) {
insert(arr,size);
}
else if(a==2) {
search( arr,size);
}
cout<<endl;

cout << "Press 1 to insert "<<endl;
cout << "Press 2 to select "<<endl;
cout << "Press 3 to break  "<<endl;
cin>>a;
cout<<endl;

}

return 0;
}

