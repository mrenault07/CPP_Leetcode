/* 

Exercices from https://pynative.com/cpp-pointers-exercises/ to masterize pointers

& : is the memory adress
pointer : holds the meomry adress

int;  // a normal int
int&; // an lvalue reference to an int value
int*; // a pointer to an int value (holds the address of an integer value)

int x{ 5 };

int* ptr;        // an uninitialized pointer (holds a garbage address)
int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
int* ptr3{ &x }; // a pointer initialized with the address of variable x
*/

#include <iostream>

using namespace std;


// 1
void print_int(){
    /*
    Declare an integer variable named value and initialize it to 100. Declare an integer pointer named ptr. 
    Assign the memory address of value to ptr. Finally, print the integer stored in value by using only the 
    pointer ptr and the dereference operator.
    */
    int value = 100;
    int* ptr;
    ptr = &value;
    cout << " The value is : " << *ptr;
}

// 2
void change_value(){
    /*
    Declare an integer variable named number initialized to 50. Declare an integer 
    pointer named num_ptr and make it point to number. Change the value of number 
    to 99 using only the pointer num_ptr. Print the final value of the variable number.
    */
   int number = 50;
   cout << "\nnumber is : " << number;
   int* num_ptr = &number;
   *num_ptr = 99;
   cout << "\nnumber is : " << number;
}

// 3
void pointer_to_pointer(){
    /* Declare an integer variable x initialized to 42. Declare an integer pointer p1 
    that points to x. Declare a double integer pointer (pointer to a pointer) p2 that 
    points to p1. Access and print the initial value of x using the double pointer p2.*/
    
}

// 16
void sub_array_printing(int* array, int start, int end ){ // un tableau se passe par pointeur *, faire int& fait référence à un entier simple
    /*    
    int data[] = {10, 20, 30, 40, 50, 60};
    int start_index = 2; // Element 30
    int end_index = 5;   // Up to element 50 (exclusive)
    sub_array_printing(data, start_index, end_index);
    // Prints : Sub-array elements: 30 40 50
    */
    const int size = end - start;
    int* ptr;
    ptr = array + start;

    for (int i = 0; i< size; i++){
        cout << *(ptr + i) << " ";
    }
}

// 17
void swap(int* a, int* b){
    /*
    int a = 10;
    int b = 20;
    swap(&a, &b);
    // Prints :
    // Before swap: a = 10, b = 20
    // After swap: a = 20, b = 10
    */
   int temp = *a;
   cout << "\nBefore swap : a = " <<*a << ", b = " << *b; // Dereference operator
   a=b; // Met l'adresse de b dans a
   b=&temp; // Met l'adresse de temp dans b
   cout << "\nAfter swap : a = " << *a << ", b = " << *b; // 
}


int main(){
    change_value();
    return 0;
}
