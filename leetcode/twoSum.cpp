#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            for (int j = i+1; j < len; ++j)
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        return result;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    Solution s;
    nums = s.twoSum(nums, 6);
    cout << nums[0] << "," << nums[1] << endl;
    return 0;
}