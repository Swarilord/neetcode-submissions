class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel = 0;
        int start = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
        }
        if(sum < 0){
            return -1;
        }
        for(int i = 0; i < gas.size(); i++){
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                fuel = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
