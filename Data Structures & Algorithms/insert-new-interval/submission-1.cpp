class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /**
            Description:
            - Insert newInterval into intervals vector such that intervals
            - is still sorted in ascending order by start_i
            - touching intervals are considered overlapping

            Summary:
            - if the interval can be merged (Overlap), we merge, if not we just insert between (No Overlap)
        **/
        vector<vector<int>> result;
        int i = 0; // declare outside loop

        for (i = 0; i < intervals.size(); i++){
            // case 1: existing interval ends before new interval start
            if (intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]){
                result.push_back(newInterval);
                break;
            }
            else{  // overlapping intervals
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }

        }

        // edge case: newInterval not yet inserted yet
        if (i == intervals.size()){
            result.push_back(newInterval);
        }

        // append remaining intervals
        for (int j = i; j < intervals.size(); j++){
            result.push_back(intervals[j]);
        }

        
        return result;

    }
};

/**
Another method:
-----------------------

for (; i < intervals.size(); i++) {
    // Process intervals

    if (.......) {
        break;
    }
}

for (; i < intervals.size(); i++) {
    result.push_back(intervals[i]);
}

Method 2
-----------------
int i = 0;

while (i < intervals.size()) {
    // Process intervals

    if (............) {
        break;
    }

    i++;
}

// Append remaining intervals
while (i < intervals.size()) {
    result.push_back(intervals[i]);
    i++;
}

-------------------------------

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Phase 1: Intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Insert the merged newInterval exactly once
        result.push_back(newInterval);

        // Phase 3: Append intervals after newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

**/