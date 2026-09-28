class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0; 
        int mid; 
        int high = nums.size() - 1;
        while(lo <= high){
            mid = (lo + high) / 2;
            if(nums[mid] < target){
                lo = mid;
                lo++;
            }
            else if(nums[mid] > target){
                high = mid;
                high--;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
