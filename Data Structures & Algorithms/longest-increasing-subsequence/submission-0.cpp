class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> DP(nums.size(), 1);
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
        }
        int max = 0;
        for(auto dp: DP){
            max = std::max(max, dp);
        }
        return max;
    }
};
