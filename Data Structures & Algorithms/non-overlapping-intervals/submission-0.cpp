class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /**
            Description: Might Involve a greedy solution

            Greedy: Keep interval that ends earlier, when 2 overlap
        **/
        int prevEnd;
        int count = 0;

        // empty input
        if (intervals.empty()){
            return 0;
        }

        // sort intervals vector by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });


        prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] < prevEnd){
                count++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }

        return count;


    }
};
