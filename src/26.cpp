#include <vector>
#include <iostream>
#include <string> 

using namespace std;


int removeDuplicates(vector<int>& nums) {
    int counter=0;
    vector<string> new_sequence;

    for (int i = 1; i< (int)nums.size(); i++){
        if(nums[i]==nums[i-1]){
            counter++;
            nums.erase(nums.begin() + i );
            i--;
        }
    }

    // Converts int to string
    for (int n : nums){
        new_sequence.push_back(to_string(n));
    }
    // Adds "_"
    for (int m =0; m < counter; m++){
        new_sequence.push_back("_");
    }
    return counter;
}

int main(){
    vector<int> nums ={1,1,2};
    
    int result = removeDuplicates(nums);
    cout << result;
    return 0;
}
