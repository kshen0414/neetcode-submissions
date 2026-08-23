class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /**
            Algorithm: Find the next largest value starting from cur index
        **/
        stack<int> st;
        vector<int> result(temperatures.size(), 0);

        // iterate the vector
        for (int i=0; i<temperatures.size(); i++){
            // if cur > stack top, push
            while(!st.empty() ){
                int prev;
                if(temperatures[i] > temperatures[st.top()]){
                    prev = st.top();
                    st.pop();
                    result[prev] = i - prev; 
                }
                else{
                    break;
                }   
            }
            st.push(i);

        }
        return result;
    }
};
