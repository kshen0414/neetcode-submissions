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
    int minMeetingRooms(vector<Interval>& intervals) {
        /**
            Idea:
            - Track when occupied rooms become available
            - find earliest ending meeting
            - reuse room if its end time is <= next meeting's start time
                - otherwise, allocate another room
            - have to use min-heap (implemented using priority_queue)

            ----> minHeap.top() <= start (reuse a room: pop() old end time)
            ----> minHeap.top() > start (need another room, don't pop())
        **/

        priority_queue<int, vector<int>, greater<int>> minHeap;

        // if a single meeting, return true
        // if (intervals.size() < 1){
        //     return 0;
        // }

        // sort intervals vector by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        for (int i = 0; i < intervals.size(); i++){
            // check if reuse a room
            if (!minHeap.empty() && minHeap.top() <= intervals[i].start){
                minHeap.pop();
            }
            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};
