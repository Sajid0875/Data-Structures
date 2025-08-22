#include<iostream>
using namespace std;
int main() {

int size ;
cout<<"Enter the size of Array "<<endl;
cin>>size ;
cout<<"Thank you"<<endl;

int *p=new int [size];

for (int i=0;i<size;i++){
	cin>>*(p+i);
}


bool Ascending= true , Descending=true ;  // using bool for detection 
for (int i=0;i<size-1;i++){
	if (*(p+i)<*(p+i+1)){
 Descending = false; 
		continue;
		
	}
	else if (*(p+i)>*(p+i+1) ){
		Ascending=false;
			continue;  
		
	}
}
 if (Ascending)
        cout << "Array is in Ascending order" << endl;
    else if (Descending)
        cout << "Array is in Descending order" << endl;
    else
        cout << "Array is in No particular order" << endl;
        
        delete []p ;


    return 0;
}
