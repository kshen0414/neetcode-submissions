class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // create a stack

        for (char c : s) { // iterate through string
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);  
                // push initial opening brackets (since we want balanced brackets)
            }
            else if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop(); // pop closing brackets
            }
            else if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop(); // pop closing brackets
            }
            else if (c == ']' && !st.empty() && st.top() == '[') {
                st.pop(); // pop closing brackets
            }
            else {
                st.push(c); // pushes invalid bracket
            }
        }
        return st.empty();  // empty return true (every bracket matches)
    }
};
