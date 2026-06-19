#include <vector>
#include <iostream>
#include <string> 

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i =0; i< nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};


int main(){
    Solution myobj;

    vector<int> cumeros = {-1,0,3,5,9,12};
    int targ = 2;
    int obj;
    obj = myobj.search(cumeros, targ);
    cout << obj;
}
