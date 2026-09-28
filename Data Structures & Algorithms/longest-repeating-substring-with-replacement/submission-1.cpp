class Solution {
public:
    int characterReplacement(string s, int k) {
        int windowSize = 0;
        int maxw = 0;
        unordered_map<int, int> freq;
        int maxf = 0;
        int i = 0;
        int j = 0;
        freq[s[0]]++;
        while(j < s.size()){
            //check if valid Window
            windowSize = j + 1 - i;
            for(auto const& [key, value]: freq){
                if(value > maxf){
                    maxf = value;
                }
            }
            if(windowSize - maxf <= k){
                j++;
                if(j < s.size()){
                    freq[s[j]]++;
                }
                if(windowSize > maxw){
                    maxw = windowSize;
                }
            }
            else{
                freq[s[i]]--;
                i++;
            }
            
        }
        return maxw;
    }
};
