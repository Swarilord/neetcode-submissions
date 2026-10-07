class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int best = INT_MAX;
            for (int c : coins) {
                if (c <= i && res[i - c] < best) {
                    best = res[i - c];
                }
            }
            if (best == INT_MAX) continue; // no i - c is reachable, so i isn't either
            res[i] = best + 1;
        }

        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};