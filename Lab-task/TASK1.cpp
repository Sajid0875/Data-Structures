git init#include <iostream>
using namespace std;

class Inventory {
private:
    int *Array;   // DMA
    int size;    

public:
   
    Inventory(int s) {  // constructor 
        size = s;
        Array = new int[size];
    }

   
    void inputValues() {
        cout << "Enter " << size << " values for inventory: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> Array[i];
        }
    }

// to cal avg
    
    double Average() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += Array[i];  
        }
        return sum / size;
    }
    
    
    // find critical products
    void CriticalProducts() {
        double avg = Average();  
        int count = 0;

        cout << "Average stock \n= " << avg << endl;
        cout << "Products below average stock =" << endl;

        for (int i = 0; i < size; i++) {
            if (Array[i] < avg) {
                cout << "Product " << (i + 1) << " with stock " <<*(Array+i) << endl;
                count++;
            }
        }

        cout << "Total critical products = " << count << endl;
    }

// finding Top selling 

double Topselling(){
double max = *Array;   // first element
for (int i = 1; i < size; i++) {
    if (*(Array + i) > max) {   
        max = *(Array + i);
    }
    
    
}
return max;

}

void SecondTop(){
    double pre_max = Topselling();
    int second_max = -1;   // better to use -1

    for (int i = 0; i < size; i++) {
        if (*(Array+i) < pre_max && *(Array+i) > second_max) {
            second_max = *(Array+i);
        }
    }

    cout << "Second top selling is " << second_max << endl;
}


void Popularity_Descending_Order() {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(Array + j) > *(Array + i)) {
                temp = *(Array + i);
                *(Array + i) = *(Array + j);
                *(Array + j) = temp;
            }
    }
}
    

    cout << "Inventory in Descending Order (Popularity) =" << endl;
    for (int i = 0; i < size; i++) {
        cout << *(Array + i) << endl;
    }
}	
       

    //Dest
    ~Inventory() {
        delete[] Array;
        cout<<"Destructor is called "<<endl;
    }
    
    
};

int main() {
    int size;
    cout << "Enter the size of your inventory: ";
    cin >> size;

    Inventory obj(size);
    obj.inputValues();

    cout << "Average is = " << obj.Average() << endl;
    
    obj.CriticalProducts();
  obj.Topselling();
  cout << "Top /max product is  = " << obj.Topselling() << endl;
  obj.SecondTop();
  obj.Popularity_Descending_Order();

    return 0;
}

