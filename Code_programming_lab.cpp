#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> threeSum(vector<int>& nums) {
  //sorts nums smallest to largest
    sort(nums.begin(), nums.end());
    //Creates an empty list to store all valid triplets
    vector<vector<int>> result;
    
    for (int i = 0; i < nums.size(); ++i) {
      //skips duplicates prevents uisng same value for i twice
        if (i > 0 && nums[i] == nums[i - 1]) continue;
//set pointer positions
        int left = i + 1;
        int right = nums.size() - 1;
        //picks each number in the array as element of a triplet
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
              //Sum is too small move left pointer rightward
                left++;
            } else if (sum > target) {
              //Sum is too big move right pointer leftward
                right--;
            } else {
              //Found a triplet that sums to zero and adds 3 numbers to the list
                result.push_back({nums[i], nums[left], nums[right]});
                //handle duplicates for the left and teh right side
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                //moves both pointers inward
                left++;
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -2, -4};
    vector<vector<int>> res = threeSum(nums);

    for (auto& triplet : res) {
        cout << "[ ";
        for (int n : triplet) cout << n << " ";
        cout << "]\n";
    }
}