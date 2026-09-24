struct Comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> m; 
        std::unordered_map<int, int> rev; 
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq(m.begin(), m.end());
        vector<int> res;
        pair<int, int> x;
        for(int i = 0; i < k; i++){
            x = pq.top();
            res.push_back(x.first);
            pq.pop();
        }
        return res;
    }
};
