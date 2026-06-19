#include <vector>
#include <iostream>
#include <string> 

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i=0; i < letters.size(); i++){
            if (int(target) < int(letters[i])) return letters[i];
        }
        return letters[0];
    }
};

int main(){
    Solution myobj;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';

    char result = myobj.nextGreatestLetter(letters, target);
    cout << result;
}
