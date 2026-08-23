class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // create a stack

        for (auto c : s) { // iterate through string
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            else if (c == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();

    }
};
