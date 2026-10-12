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
        std::sort(intervals.begin(), intervals.end(), 
        [](const Interval& a, const Interval& b){return a.start < b.start;}
        );
        int active_intervals = 0;
        int max_intervals = 0;
        std::priority_queue<int, std::vector<int>, greater<int>> ends;
        for(int i = 0; i < intervals.size(); i++){
            active_intervals++;
            ends.push(intervals[i].end);
            while(ends.top() <= intervals[i].start){
                ends.pop();
                active_intervals--;
            }
            max_intervals = std::max(active_intervals, max_intervals);
        }
        return max_intervals;
    }
};
