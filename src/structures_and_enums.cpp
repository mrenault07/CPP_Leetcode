/*
Exercices from : https://pynative.com/cpp-oop-exercises/
*/

#include <iostream>
#include <string>
#include <array>

using namespace std;


// 1
/*Create a structure named Book to hold information about a library book. The structure 
must contain three members: a std::string for the book’s title, a std::string for the 
author’s name, and a float for the book’s price.*/
struct Book{
    string title {};
    string author_name {};
    float price {};
};
/* In main :
Book book {};
book.author_name = "M.C. Beaton";
book.title = "La quiche fatale";
book.price = 0.0;
cout << book.title << " by " << book.author_name << endl;
cout << "Price : " << book.price;
*/

// 2
void get_bookInfo(){
    /*Using the Book structure defined in Exercise 2, write a complete C++ program that prompts 
    the user to enter the title, author, and price for a single book. After reading the input, 
    the program should display all the captured information back to the console.*/
    Book book {};
    cout << "Author's name : ";
    getline(cin, book.author_name); // Pour avoir les espaces (cin ne les prend pas)
    cout << "Title : ";
    getline(cin, book.title);
    cout << "Price : ";
    cin >> book.price;
    cout << "You're looking for " << book.title << " by " << book.author_name << "\nThe price is : " << book.price;
}

// 3
/*Declare an array capable of storing information for 3 Book structures. Write a program 
to loop through the array, prompting the user to input the data (title, author, price) for
each of the 3 books. Finally, loop through the array again to display the data for all 3 
books.*/
void array_of_structures(){
    array<Book, 3> books{};
    for (int i = 0; i < 3; i++){
        cout << "\nBook " << i + 1 << endl <<endl;
        cout << "Author's name : ";
        getline(cin, books[i].author_name); // Pour avoir les espaces (cin ne les prend pas)
        cout << "Title : ";
        getline(cin, books[i].title);
        cout << "Price : ";
        cin >> books[i].price;
        // Lorsque l'utilisateur appuie sur la touche espace, "\n" va dans le buffer de cin et n'est jamais enlevé.
        // A la 2e itération de i, il y a donc "\n" dans le buffer.
        // Il faut donc vider le buffer avant une prochaine itération.
        cin.ignore();
    }

    for(int j = 0; j < 3; j++){
        cout << "\nYou're looking for " << books[j].title << " by " << books[j].author_name << endl;
        cout << "The price is : " << books[j].price << endl;

    }
}

// 4
float calculate_total_price(array<Book, 3> books, int nb){
    /*Building upon the array of Book structures, write a function named calculate_total_price. 
    This function should accept the array of Book structures and the number of books as arguments. 
    It must return a float representing the sum of the prices of all books in the array.*/
    float sum = 0.0;
    for (int i=0; i < nb; i++){
        sum += books[i].price;
    }
    return sum;
}

int main(){
    array books {
        Book{"title1", "author1", 9.4},
        Book{"title2", "author2", 3.0},
        Book{"title3", "author3", 5.6}
    };
    float total_price = calculate_total_price(books, 3);
    cout << "Total price : " << total_price << endl;
    return 0;
}
