#include <iostream>

using namespace std;

int main() {
cout<<"LINEAR SEARCH"<<endl;

int noofdata;
cout<<"Enter the no of data you want to enter:"<<endl;
cin>>noofdata;

int array[noofdata];
int h;
for(h=0;h<noofdata;h++){
	cout<<"Enter the value at index("<<h<<") :"<<endl;
	cin>>array[h];
}
for(int y=0;y<noofdata;y++){
	cout<<"The value of index("<<y<<") is :"<<array[y]<<endl;
}
int data;
cout<<"Enter the number you want to find : ";
cin>>data;
int m;
for( m=0;m<noofdata;m++){
	if(array[m]==data){
		cout<<"The value "<<data<<" is find at index("<<m<<") , which is at the number "<<m+1<<endl;
		break;
	}
}
if(m==noofdata){
	cout<<"The value "<<data<<" is not in array";
	return 0;
}

}
