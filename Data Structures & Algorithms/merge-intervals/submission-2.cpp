class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /**
            Description: Merge all overlapping intervals
            - No overlap: Keep Both intervals
            - Overlap: Merge them into one interval
        **/

        vector<vector<int>> result;

        // edge case: empty vector
        if(intervals.size() == 0){
            return {};
        }

        // sort by start time
        sort(intervals.begin(), intervals.end());

        // insert first interval
        result.push_back(intervals[0]);


        for (int i = 1; i < intervals.size(); i++){  // start to merge, or return original
            if (intervals[i][0] <= result.back()[1]){   // result.back()[1] mean end of last merged interval
                // then merge
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
