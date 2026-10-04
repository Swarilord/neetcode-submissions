class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> clos;
        std::unordered_map<char, char> open;
        clos[')'] = '(';
        clos[']'] = '[';
        clos['}'] = '{';
        std::stack<char> st;

        for(auto c: s){
            st.push(c);
            if(c == ')'){
                st.pop();
                if(st.empty()){
                    return false;
                }
                if(!(st.top() == clos[c])){
                    return false;
                }
                st.pop();
            }
            if(c == '}'){
                st.pop();
                if(st.empty()){
                    return false;
                }
                if(!(st.top() == clos[c])){
                    return false;
                }
                st.pop();
            }
            if(c == ']'){
                st.pop();
                if(st.empty()){
                    return false;
                }
                if(!(st.top() == clos[c])){
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
 