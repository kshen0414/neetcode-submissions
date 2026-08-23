class Solution {
private:
    const char delimiter = '/';

public:

    string encode(vector<string>& strs) {
        // since the idea is to encode the list of strings into a single string
        // but what we have to consider is that, we might need a delimiter
        // or else we are not able to decode the single string

        string encoded;
        for(string &str: strs){  // assigning each string in strs

            encoded += to_string(str.length())+delimiter;  // Ex: "neet", 4/ ...

            encoded += str;   // Ex: "neet, code", 4/neet4/code
        }
        
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i=0;

        while(i<s.length()){ // iterate through each character in combined single string "..."
            // determine delimiter position
            size_t delimiterPos = s.find(delimiter,i);

            // determine the length of original string
            int length = stoi(s.substr(i,delimiterPos-i));  // 4

            // start of the index for valid string
            i = delimiterPos+1;  // i=3

            // abstract the valid substring after the delimiter
            string str = s.substr(i,length);

            decoded.push_back(str);

            // new index i for next string
            i+=length;
        }
        return decoded;
    }
};
