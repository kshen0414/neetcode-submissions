class Solution {
public:
    bool isPalindrome(string s) {
        /**
        Approach: Two pointers
            - create a start and end pointer
            - then use a while loop to iterate the string
        **/
        int start=0, end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }

            if(!isalnum(s[end])){
                end--;
                continue;
            }

            // else if(!isalnum(s[start] || !isalnum(s[end]))){
            //     continue;
            // }

            // check the first occurence where char does not match
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};