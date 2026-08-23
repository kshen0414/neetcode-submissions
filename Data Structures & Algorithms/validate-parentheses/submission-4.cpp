class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = {
            {')', '('}, 
            {']', '['},
            {'}', '{'}
        };

        for (char c:s ){
            if(match.count(c)){
                if(st.empty() || match[c] != st.top()){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        return st.empty();
    }
};
