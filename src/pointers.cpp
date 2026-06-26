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
#include <cctype>

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
    int x = 42;
    int* p1 = &x;
    int* p2 = p1;
    cout << *p2;
}

// 4
void increment(){
    /*Declare an integer array named data with the elements {10, 20, 30, 40, 50}. Declare 
    an integer pointer data_ptr and point it to the first element of the array. Use 
    pointer increment (ptr++) and the dereference operator to traverse the array and 
    print all five elements.*/
    int data[] = {10, 20, 30, 40, 50};
    int* ptr;
    ptr = &data[0];
    cout << "Size of int : " << sizeof(int) << "\n";
    for (int i: data){
        cout << *(ptr) << " ";
        ptr++; // increment pointer to the next adress, depending on the variable
        // Here, increment of 4 bytes (int size)
    }
}

//5
void index(){
    /*Declare an integer array named scores with elements {85, 90, 78, 95, 88}. Declare a 
    pointer score_ptr and point it to the first element. Access and print the third element 
    (which is 78) of the array using pointer arithmetic in the form *(ptr + N).*/
    int scores[] = {85, 90, 78, 95, 88};
    int* score_ptr = &scores[0];
    cout << "The third element is :" << *(score_ptr + 2); 
}

// 6
void index_char(){
    /*Declare a char array word[] = "CODE". Declare a char pointer p pointing to the 
    beginning of the array. Use pointer arithmetic (p + N) and the dereference operator to 
    print the third character (‘D’) of the array.*/
    char word[] = "CODE";
    char* p = &word[0];
    cout << "Third character is : " << *(p + 2);
}

// 7
void check_null_pointer(){
    /*Declare an integer pointer named safe_ptr and initialize it to nullptr. Write a 
    conditional statement to check if the pointer is null before attempting to dereference 
    it. If it is null, print “Pointer is null, cannot dereference.” If it is not null, 
    initialize a variable, assign its address to the pointer, and print the dereferenced value.*/
    int x = 9;
    int* safe_ptr = nullptr;

    if (safe_ptr == nullptr) cout << "Pointer is null, cannot dereference.";
    if (safe_ptr != nullptr){
        int var = 12;
        safe_ptr = &var;
        cout << *safe_ptr;
    }
}

// 8
void increment_value(int* ptr){
    /*Write a function named increment_value that takes an integer pointer as its only 
    argument. Inside the function, increment the value that the pointer points to by 10. 
    In main, call the function using the address of an integer variable and print the updated value.*/
    *ptr += 10;

    /* In main :
    int x = 5;
    increment_value(&x);
    cout << " x : " << x;
    */
}

// 9
void size_comparizon(){
    /*Declare an integer variable i and an integer pointer ptr. Use the sizeof() operator 
    to print the size (in bytes) of the i variable and the size of the ptr pointer on your 
    system. Note and discuss the difference between the two sizes.*/
    int i = 0;
    int* ptr;
    cout << "\nSize of int : " << sizeof(i);
    cout << "\nSize of pointer : " << sizeof(ptr);
    ptr = &i;
    cout << "\nSize of pointer pointing to i : " << sizeof(ptr);
}

// 10
void array_sum(){
    /*Write a program to calculate and print the sum of all elements in a given integer 
    array {1, 5, 10, 15, 20} using only pointer arithmetic to access the elements. Do not 
    use the array index operator ([]).*/
    int data[] = {1, 5, 10, 15, 20};
    int* ptr = data;
    int sum = 0;
    for (int i : data){ //iterating through values
        sum += *ptr;
        ptr++;
    }
    // OR
    sum = 0;
    int size = sizeof(data) / sizeof(int);
    for (int j = 0; j < size; j++){ // iterating through indices
        sum += *(ptr + j);
    }
    cout << "\nSum of all elements : " << sum;
}

// 11
void reverse_array(){
    /*Write a program to print the elements of an integer array {1, 2, 3, 4, 5} in 
    reverse order using only pointer notation and arithmetic. You must not use the array 
    index operator ([]).*/
    int data[] = {1, 2, 3, 4, 5};

    int size = (sizeof(data) / sizeof(int)) - 1;
    cout << "Array size : " << size <<"\n";

    int* ptr = &data[size];

    for (int i : data){
        cout << *ptr << " ";
        ptr--;
    }
}

// 12
int* find_min_ptr(int arr[], int size){
    /*Write a function named find_min_ptr that takes an integer array and its size as 
    input, and returns a pointer to the smallest element in that array. In the main 
    function, call this function and use the returned pointer to print the minimum value.*/
    int* min = arr;
    for (int i = 0 ; i < size; i++){
        if (*min > *(min + i)){
            *min = *(min + i);
        }
    }
    return min;

    /* In main :
    int data[] = {45, 12, 67, 8, 33};
    int* ptr = find_min_ptr(data, 5);
    cout << "min value : " << *ptr;
    */
}

// 13
void matrix(){
    /*Declare a small two-dimensional integer array, for example, a 3×3 array initialized 
    with values. Write a program that uses an integer pointer to access and print all 
    elements of the 2D array, treating it as a contiguous block of memory. You must use 
    pointer arithmetic, not standard bracket indexing ([][]).*/
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int (*ptr)[3]; // Pointeur vers un array de 3 int
    ptr = matrix;  // Pointe vers la première ligne de matrix
    for (int i=0; i < 3; i++){ // itération des lignes
        for (int j=0; j < 3; j++){ // itération des colonnes
            cout << *(*(ptr + i) + j) << " ";
        }
    }
    cout << "\n De maniere contigu : \n";
    // OU
    // en mémoire, chaque adresse des valeurs de matrix se suivent
    // int* ptr2 = (int*)matrix; // fonctionne aussi. pointe vers un pointeur int
    int* ptr2 = &matrix[0][0];
    for (int k=0; k < 9; k++){
        cout << *(ptr2 + k) << " ";
    }
}

// 15
void compare_arrays(int array1[], int array2[], int size1, int size2){
    /*Write a function named compare_arrays that takes two integer arrays and their size
     as input. The function should use pointers to check if the two arrays are identical 
     (i.e., they have the same size and the same elements in the same order). Return true 
     if they are identical, and false otherwise.*/
    int* ptr1 = array1;
    int* ptr2 = array2;
    cout << "\n";

    if (size1 != size2){
        cout << "Not identical.";
        return;
    }

    for (int i=0; i < size1; i++){
        if ( *(ptr1 + i) != *(ptr2 + i)){
            cout << "Not identical."; return;
        }
    }
    cout << "Arrays are identical.";

    /* In main :
    int a1[] = {1, 2, 3, 4};
    int a2[] = {1, 2, 3, 4};
    int a3[] = {1, 2, 9, 4};
    compare_arrays(a1, a2, 4, 4);
    compare_arrays(a1, a3, 4, 4);
    */
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

// 18
void to_uppercase(){
    /*Write a function named to_uppercase that takes a character pointer (char*) 
    representing a C-style string. The function must iterate through the string using 
    pointer arithmetic and modify the characters in place to convert all lowercase 
    letters to uppercase. Use the standard library function toupper() from <cctype>.*/

    char text[] = "hello pointers exercise";
    cout << text << "\n";
    char* ptr = text;
    const int size = sizeof(text)/sizeof(char);

    for(int i = 0; i < size - 1; i++){
        *(ptr + i) = toupper(*(ptr+i));
    }
    cout << text;
}

// 19
int add(int a, int b){
    /*Write a simple function add that takes two integers and returns their sum. In 
    main, declare a function pointer that can point to a function with this signature. 
    Assign the add function to this pointer and then call the add function using the 
    function pointer.*/
    return (a + b);

    /* in main :
    int (*fctptr)(int, int); // initialise un pointeur sur une fonction qui prend en paramètres 2 int et qui retourne un int
    fctptr = add; // pointe sur l'adresse de la fonction add
    // int (*fctptr)(int, int){&add}; // fonctionne aussi
    if (fctptr){ // vérifie que fcptr n'est pas un nullptr
        int result = fctptr(3,4);
        cout << result;
    }
*/
}

// 20
int multiply(int a, int b) {return (a*b);}
int substract(int a, int b) {return (a-b);} 

void compute_result(int a, int b, int (*fctptr)(int, int)){
    /*Define two simple functions: multiply(int, int) and subtract(int, int). 
    Write a function called compute_result that takes three arguments: two integers
    and a function pointer (which must match the signature of multiply or subtract). 
    Inside compute_result, use the function pointer to perform the operation on the 
    two integers and return the result. Use compute_result to call both multiply 
    and subtract.*/
    cout << "\nOperation : " <<  fctptr(a, b);

    /* in main :
    int (*fctptr)(int,int);
    compute_result(3,5, multiply);
    compute_result(3,5, substract);
    */
}

// 21
void print_constant_value(const int* ptr){
    /*Write a function named print_constant_value that accepts a pointer to a 
    constant integer (const int*). Inside the function, print the value pointed to. 
    In main, attempt to call the function and then try to use the pointer inside the 
    function to modify the pointed-to value. Observe and explain the resulting 
    compilation error.*/
    cout << *ptr;

    // Try to modify value pointed by ptr
    // *ptr = 10;
    // getting error : expression must be a modifiable lvalue
    // Although the value is not constant, the function will treat it as so. It can be accessed only as read only

    /*In main :
    int x = 9;
    print_constant_value(&x);
    x = 10;
    print_constant_value(&x);
    */
}

// 22
void constant_pointer(){
    /*Declare an integer variable x initialized to 5. Declare a constant pointer to 
    an integer (int* const) named const_ptr and initialize it to point to x. Use the 
    pointer to successfully change the value of x to 10. Then, declare a second 
    integer y and attempt to make const_ptr point to y. Observe and explain the 
    resulting compilation error.*/
    int x = 5;
    int* const const_ptr = &x;
    *const_ptr = 10;
    int y = 3;
    // const_ptr = &y; // error :'const_ptr' : vous ne pouvez pas assigner une variable const
    *const_ptr = 3; // ok
    /*The const modifier is placed after the asterisk, making the pointer address itself immutable.
    Thus, the pointer must always point to the address of x and cannot be reassigned to 
    point to y. However, since the data type (int) is not constant, the value at the address 
    (i.e., x) can be freely changed using the dereference operator (*const_ptr = 10).*/
}

// 23
struct Rectangle {
    int length {};
    int width {};
};

void pointer_to_struct(){
    /*Define a structure named Rectangle with two integer members: length and 
    width. Declare a Rectangle variable, initialize its members, and then declare 
    a pointer to that structure. Access and modify the structure members using the 
    arrow operator (->). Print the final dimensions.*/
    Rectangle rect {}; 
    rect.length = 5;
    rect.width = 4;
    
    struct Rectangle *ptr;
    ptr = &rect;
    ptr->length = 10; // -> accède aux membres de struct via le pointeur.
    //Déréférence automatiquement et accède à la valeur pointée
    cout << rect.length;
}

// 24
void dynamic_allocation(){
    /*Use the new operator to dynamically allocate memory for a single float 
    variable on the heap. Store the address in a float pointer. Initialize the 
    allocated memory to the value 3.14. Print the value, and then use the delete 
    operator to deallocate the memory.*/
    float* ptr = new float;
    *ptr = 3.14;
    cout << *ptr;
    delete(ptr);
    ptr = nullptr; // avoid dangling pointer
}

// 25 
void dynamic_allocation_array(){
    /*Use the new[] operator to dynamically allocate an integer array of size 8. 
    Use a pointer to fill the array with the values 10, 20, 30, …, 80. Print all 
    values using pointer arithmetic traversal. Finally, use the delete[] operator 
    to correctly deallocate the entire array.*/
    int* ptr = new int[8];

    for(int i = 1; i < 9; i++){
        *(ptr + i) = 10 * i ;
    }
    for(int i = 1; i < 9; i++){
        cout << *(ptr + i) << " ";
    }
    delete[] ptr; // deallocate an array
    ptr = nullptr;
}

// 26
void array_of_pointers(){
    /*Declare five individual integer variables (e.g., n1, n2, …). Declare an 
    array of 5 integer pointers (int* array_of_ptrs[5]). Make each element in the 
    array of pointers point to one of the five individual integer variables. Use 
    the array of pointers to print all five integer values.*/
    int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
    int* array_of_ptrs[5];

    array_of_ptrs[0] = &n1;
    *(array_of_ptrs + 1) = &n2; // pareil
    array_of_ptrs[2] = &n3;
    array_of_ptrs[3] = &n4;
    array_of_ptrs[4] = &n5;

    for (int i = 0; i < 5; i++){
        cout << *(*(array_of_ptrs + i)) << " "; 
    }
}

// 27
void find_first_occurrence(){
    /*Write a function named find_first_occurrence that mimics a simplified strstr. 
    It takes two char pointers: a source string and a target string (substring). It 
    should search for the first occurrence of the target substring within the source 
    string. If found, the function must return a pointer to the starting character of 
    the match within the source string. If not found, return nullptr.*/
    
}

int main(){
    array_of_pointers();
    return 0;
}
