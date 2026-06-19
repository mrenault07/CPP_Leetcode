#include <vector>
#include <iostream>
#include <string> 

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] > target){
                return i;
            }
        }
        return nums.size(); // si target est plus grand que tout le tableau
    }
};

int main(){
    Solution myobj;
    vector<int> nums = {1,3,7};
    int target = 5;

    int result = myobj.searchInsert(nums, target);
    cout << result;
}
