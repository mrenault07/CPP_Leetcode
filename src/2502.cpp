#include <vector>
#include <iostream>
#include <string> 

using namespace std;

class Allocator {
private:
    int* ptr; // est accessible dans toute la classe
    int size;
    int n;
public:
    Allocator(int n) {
        ptr = new int[n](); // () pour initialiser toutes les cases à 0
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        int counter = 0;
        for (int i=0; i < n; i++){
            if(ptr[i] == 0){ // if ptr[i] is not allocated, allocate it
                counter++;
            }else{
                counter = 0;
            }
            if (counter == size){ // if we found enough cases
                int start = i - counter +1;
                for (int k=0; k < size; k++){
                    ptr[start + k] = mID;
                }
                return start;
            }
        }return -1;
    }
    
    int freeMemory(int mID) {
        int counter = 0;
        for (int i = 0; i < n; i++){
            if (ptr[i] == mID){
                ptr[i] = 0;
                counter++;
            }
        }return counter;
    }
    ~Allocator(){ // Destructeur. Appelé automatiquement lorsque l'objet est détruit.
        delete[] ptr; 
    }
};



int main(){

    return 0;
}


