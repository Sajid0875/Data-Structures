#include <iostream>
using namespace std;
class DuplicateRemover {
private:
    int size;
    int originalSize;
    int *array;
public:
    DuplicateRemover() {
	        cout << "Enter the size of array: ";
        cin >> size;
        originalSize = size;
        array = new int[size]; 
        cout << "Enter " << size << " values "<<endl;
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
        cout << "Original array "<<endl;
        displayArray();
    }
    
    void removeDuplicates() {
      for (int i = 0; i < size; i++) {
     for (int j = i + 1; j < size; j++) {
      if (array[i] == array[j]) {
        for (int k = j; k < size - 1; k++) {
   array[k] = array[k + 1];
    }
  size--; 
  j--;   
  }
     }
	 }
	  cout << "Array after removing duplicates: ";
        displayArray();
  
  }
    void display() {
       
        cout << "original size: " << originalSize << endl;
        cout << "final size " << size << endl;
        cout << "duplicates removed " << (originalSize - size) << endl;
    }
    
    // Destructor
    ~DuplicateRemover() {
        delete[] array; 
        cout << "destructor call" << endl;
    }
};

int main() {
    DuplicateRemover remover;
    remover.removeDuplicates();
    remover.display();
    return 0;
}

