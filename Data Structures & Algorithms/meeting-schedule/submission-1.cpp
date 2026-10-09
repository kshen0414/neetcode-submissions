/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        /**
            Algorithm:
            - Finding intervals
            - access the Interval object like
              ----> intervals[0].start, intervals[0].end
        **/

        // if single meeting, return true
        if (intervals.size() < 2){
            return true;
        }

        // sort the intervals vector using lambda function, by start time
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { return a.start < b.start; });

        for (int i = 0; i < intervals.size() - 1; i++){

            if (intervals[i].end > intervals[i+1].start){
                return false;
            }

        }

        return true;
    }
};
