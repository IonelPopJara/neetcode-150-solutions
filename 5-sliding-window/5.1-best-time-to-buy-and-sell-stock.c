// @leet start
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    // Initialize maxProfit
    int maxProfit = 0;

    // If there's only one price, we return 0 profit
    if (pricesSize == 1) {
        return maxProfit;
    }

    // Initialize pointers
    int buy = 0;
    int sell = 1;

    // Iterate through the array O(n)
    while (sell < pricesSize) {
        if (prices[buy] > prices[sell]) {
            // If the price to buy is greater than the price to sell
            // we make no profit
            // so we move or buying pointer to the selling pointer
            // because we've found a minimum
            buy = sell;
        } else {
            // Otherwise, calculate the current profit and
            // update maxProfit if needed
            int profit = prices[sell] - prices[buy];
            maxProfit = MAX(profit, maxProfit);
        }
        sell++;
    }

    return maxProfit;
}
// @leet end
