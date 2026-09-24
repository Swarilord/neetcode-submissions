class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size() - 1;
        int i = 0;
        int j = n;
        int diff = std::abs('a' - 'A');
        while(i <= j){
            while(i < j && !((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0'))){
                i++;
            }
            while(j > i && !((s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= 'z' && s[j] >= 'a') || (s[j] <= '9' && s[j] >= '0'))){
                j--;
            }
            if(s[i] != s[j]){
                if(!(((s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= 'z' && s[j] >= 'a')) &&
                    ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a'))
                    && (std::abs(s[i] - s[j]) == diff))){
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
};
