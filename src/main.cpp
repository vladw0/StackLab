#include "stack.h"

int main(){
    TStack<int> A;
    TStack<int> B(3);
    B.Push(11);
    TStack<int> C = B;
    int** data = new int* [11];
    data[0] = new int (5);
    data[1] = new int (11);
    for (int i = 2; i < 11; i++){
        data[i] = nullptr;
    }
    TStack<int> D(data, 5);
    TStack<int> E(&(data[5]), 6);

    int k = D.Pop();

    for (int i = 0; i < 11; i++){
        if (data[i] != nullptr){
            delete data[i];
            data[i] = nullptr;
        }
    }
    delete [] data;
    return 0;
}