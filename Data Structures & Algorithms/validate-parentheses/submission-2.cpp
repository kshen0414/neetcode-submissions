class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c: s){
            // check for the left opening bracket
            if(c == '(' || c== '{' || c=='[' ){
                st.push(c);
            }
            // check for right opening brackets
            else if(!st.empty() && c==')' && st.top()=='('){
                st.pop();
            }
            // check for right opening brackets
            else if(!st.empty() && c=='}' && st.top()=='{'){
                st.pop();
            }
            // check for right opening brackets
            else if(!st.empty() && c==']' && st.top()=='['){
                st.pop();
            }
            else{
                st.push(c); // for invalid character
            }
        }
        return st.empty(); // if is empty, return true
    }
};
