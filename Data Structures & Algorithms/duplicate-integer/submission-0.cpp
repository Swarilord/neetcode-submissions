class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> c;
        for(int i = 0; i < nums.size(); i++){
            c[nums[i]]++;
            if(c[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};