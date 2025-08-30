#include<iostream>
using namespace std;

class Array{
    private:
        int *arr;
        int size;
    public:
        Array(int s){
            size=s;
            arr=new int[size];
        }
        void input(){
            for(int i=0;i<size;i++){
                cout<<"Enter the value for index "<<i+1<<endl;
                cin>>*(arr+i);
            }
        }

      int Mostrepeated() {
    int maxCount = 0;
    int mostRepeated = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && arr[i] > mostRepeated)) {
            maxCount = count;
            mostRepeated = arr[i];
        }
    }
    
    cout << "Most repeated element is " << mostRepeated << " and it appears " << maxCount << " times" << endl;
    return mostRepeated;
}
    
        ~Array(){
            delete[] arr;
        }
};
  int main(){

int  size ;
cout<<"Enter the size of array "<<endl;
cin>>size;
Array arr(size);
arr.input();
arr.Mostrepeated();


return 0;

  }

