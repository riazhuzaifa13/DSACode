#include <iostream>

using namespace std;

int main() {
	cout<<"BINARY SEARCH:"<<endl;
	int noofvalue;
	cout<<"Enter how many value you want to enter"<<endl;
	cin>>noofvalue;
	
	int array[noofvalue];
	cout<<"Enter the values in ascending order."<<endl;
	for(int i=0;i<noofvalue;i++){
		cout<<"Enter the value at index("<<i<<") :"<<endl;
		cin>>array[i];
	}
	for(int j=0;j<noofvalue;j++){
		cout<<"The value at index("<<j<<") is :"<<array[j]<<endl;
	}
	int findno;
	cout<<"Enter the number you want to find:"<<endl;
	cin>>findno;
	int left=0;
	int right=noofvalue-1;
	while(left<right){
		int mid=(left+right)/2;
		if(findno==array[mid]){
			cout<<"The number "<<findno<<" is at index("<<mid<<")"<<endl;
			break;
		}else if(findno>array[mid]){
			left=mid+1;
		}else if(findno<array[mid]){
			right=mid-1;
		}
	}return -1;
}
