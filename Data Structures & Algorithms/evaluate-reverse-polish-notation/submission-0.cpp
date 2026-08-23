class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string c : tokens){
            if (c =="+" || c=="-" || c=="*" || c=="/"){
                int a,b;
                b = st.top();
                st.pop();

                a = st.top();
                st.pop();

                if(c =="+"){
                st.push(a+b);
                }
                else if(c=="-"){
                    st.push(a-b);
                }
                else if(c=="*"){
                    st.push(a*b);
                }
                else{
                    st.push(a/b);
                }
            }

            else{
                int d = stoi(c);
                st.push(d);
            }

        }
        return st.top();
    }
};
