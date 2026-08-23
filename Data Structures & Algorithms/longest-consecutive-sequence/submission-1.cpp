class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // since we are aiming O(n) time
        // either use hash map or hash set

        unordered_set<int> set;
        for(const int &num : nums){
            set.insert(num);
        }

        int longest=0;
        for(const int &start : set){

            // below method is for c++ 20 compilers
            // if(!set.contains(start - 1)){
            //     int end = start+1;
            //     while (set.contains(end)){
            //         end++;
            //     }
            //     longest = max(longest, end-start);
            // }


            // for GCC 9.2.0
            if(set.find(start - 1)== set.end()){
                int end = start+1;
                while (set.find(end)!=set.end()){
                    end++;
                }
                longest = max(longest, end-start);
            }
        }
        return longest;
    }

};
