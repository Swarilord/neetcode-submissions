class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;
        for(auto a: stones){
            pq.push(a);
        }
        int a;
        int b;
        while(!pq.empty()){
            a = pq.top();
            pq.pop();
            if(pq.empty()){
                return a;
            }
            b = pq.top();
            pq.pop();
            if(a == b){
                continue;
            }
            if(b < a){
                pq.push(a - b);
            }
        }
        return 0;
    }
};
