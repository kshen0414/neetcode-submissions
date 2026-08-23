class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort the string s, and string t
        // we create copies of the string
        string sorted_s = s;
        string sorted_t = t;

        // sort(str.begin(), str.end()) is a built in function
        // it does not return a value
        sort(sorted_s.begin(),sorted_s.end()); 
        sort(sorted_t.begin(),sorted_t.end());

        if(sorted_s == sorted_t){
            return true;
        }
        else{
            return false;
        }
    }
};
