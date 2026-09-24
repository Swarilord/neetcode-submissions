class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> c;
        for(int i = 0; i < nums.size(); i++){
            if(c.count(nums[i]) > 0){
                return true;
            }
            c.insert(nums[i]);
        }
        return false;
    }
};