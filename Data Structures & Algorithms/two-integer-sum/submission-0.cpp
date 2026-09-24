class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tar;
        for(int i = 0; i < nums.size(); i++){
            if(tar.contains(target - nums[i])){
                int k = target - nums[i];
                int r = std::min(i, tar[k]);
                int m = std::max(i, tar[k]);
                return {r, m};
            }
            tar[nums[i]] = i;
        }   
    }
};
