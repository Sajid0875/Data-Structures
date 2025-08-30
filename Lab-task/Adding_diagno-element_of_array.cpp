#include <iostream>
using namespace std;

class Duplicates{
    int *arr, n;
public:
    Duplicates(int size){
        n=size;
        arr=new int[n];
    }
    void input(){
        cout<<"Enter "<<n<<" elements: ";
        for (int i=0; i<n; i++)
            cin>>arr[i];
    }
    void removeDuplicates(){
        int newSize =0;
        for (int i=0; i<n; i++) {
            bool found =false;
            for (int j=0;j<newSize;j++){
                if(arr[i] == arr[j]){
                    found=true;
                    break;
                }
            }
            if (!found){
                arr[newSize++]=arr[i];
            }
        }
        cout<<"Array after removing duplicates: ";
        for(int i=0;i<newSize;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    Duplicates obj(n);
    obj.input();
    obj.removeDuplicates();
    return 0;
}
