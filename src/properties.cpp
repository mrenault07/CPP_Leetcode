/*
Exercices from : https://pynative.com/cpp-oop-exercises/
*/

#include <iostream>

using namespace std;


// 1
class Rectangle {
private:
    int length = 10;
    int width = 5;
public :
    int calculate_area(){
        return length * width;
    }
    int calculate_perimeter(){
        return 2 * length + 2 * width;
    }
    /*In main :
    Rectangle rect;
    cout << "Perimeter : " << rect.calculate_perimeter();
    cout << "\nArea : " << rect.calculate_area();
    */
};

int main(){

    return 0;
}
