class Solution {
public:
    bool isPalindrome(string s) {
        /**
            The idea is to basically reverse the string
            then check if revresed string is the same
            as original string?

            Realization, we have to go one step further
            We must only consider alphanumeric (alphabets and numbers)
            Also, we must make it case insensitive
        **/
        string rev_s = string(s.rbegin(), s.rend()); //reverse the string
        
        // to check if string contains only alphabets and numbers
        string ans = "";
        for(auto ch: rev_s){
            if(isalpha(ch)|| isdigit(ch) || isalnum(ch)){ //only add alphabets, numbers too
                // ch = tolower(ch); // convert to lowercase
                ans += ch;
            }
        }

        // remove extra white space from original string
        string ans_2 = "";
        for(auto ch: s){
            if(isalpha(ch)|| isdigit(ch) || isalnum(ch)){ //only add alphabets, numbers too
                // ch = tolower(ch); // convert to lowercase
                ans_2 += ch;
            }
        }

        // lowercase the original string
        std::transform(ans_2.begin(), ans_2.end(), ans_2.begin(), ::tolower);

        // lowercase the rev_string
        std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

        if(ans_2==ans){
            return true;
        } 
        else {
            return false;
        }
    }
};
