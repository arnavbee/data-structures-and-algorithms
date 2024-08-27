 int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();

        int profit = 0;

        for(int i = 1; i < n; i++){
            int cost = prices[i] - mini;
            profit = max(cost, profit);
            mini = min(mini, prices[i]);
        }
        return profit;
    }