class Solution {
public:
    bool is_pos(vector<int>& piles, int k, int h){
        int n = piles.size();
        int count = 0;
        int i = 0;
        while(i < n){
            count += std::ceil((double)piles[i]/k);
            if(count > h){
                return false;
            }
            i++;
        }
        return true;   
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //nlogn
        std::sort(piles.begin(), piles.end());
        int n = piles.size();
        int upper = piles[n - 1];
        int lower = 1;
        int k;
        while(lower != upper){
            k = (upper + lower) / 2;
            if(is_pos(piles, k, h)){
                upper = k;
            }
            else{
                lower = k + 1;
            }
        }
        return upper;
    }
};
