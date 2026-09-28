class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int i = 0;
        int j = 0;
        int maxw = 0;
        bool valid = true;
        unordered_map<int, int> freq;
        int currentw = 0;
        freq[s[0]]++;
        while(j < s.size()){
            currentw = j - i + 1;
            for(auto const& [key, value]: freq){
                if(value > 1){
                    valid = false;
                }
            }
            if(valid){
                j++;
                if(j < s.size()){
                    freq[s[j]]++;
                }
                if(currentw > maxw){
                    maxw = currentw;
                }
            }
            else{
                freq[s[i]]--;
                i++;
            }
            valid = true;
        }
        return maxw;
    }
};
