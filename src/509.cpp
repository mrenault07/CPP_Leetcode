#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    vector<int> sequence={0,1};
    int result = 0;

    if (n == 0){
        result = sequence.front();
    }else if (n == 1){
        result = sequence.back();
    }else{
        for(int i=2; i<=n;i++){
            int val = sequence[i-1] + sequence[i-2];
            sequence.push_back(val);
        }
        result = sequence.back();
    }
    return result;
}

int fib_recursive(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

int main(){
    int test = fib_recursive(8);
    cout << test << endl;
    return 0;
}
