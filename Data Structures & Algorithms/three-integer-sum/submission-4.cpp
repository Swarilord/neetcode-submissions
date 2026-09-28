#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int target;
        int i,j;
        for(int x = 0; x < (int)nums.size() - 2; x++){
            if(x > 0 && nums[x] == nums[x - 1]) continue;
            if(nums[x] > 0){
                return result;
            }
            target = -nums[x];
            i = x + 1;
            j = nums.size() - 1;
            while(i < j){
                if(nums[i] + nums[j] < target){
                    i++;
                    
                }
                else if(nums[i] + nums[j] > target){
                    j--;
                }
                else{
                    result.push_back({nums[x], nums[i], nums[j]});
                    i++;
                    j--;
                    while(j > i && nums[j] == nums[j + 1]){
                        j--;
                    }
                    while(i < j && nums[i] == nums[i - 1]){
                        i++;
                    }
                }
            }
        }
        return result;
    }
};
