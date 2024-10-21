// @leet start
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1) {
        return 0;
    }
    int buy = 0;
    int sell = 1;
    int maxProfit = 0;

    while (sell < pricesSize) {
        if (prices[buy] > prices[sell]) {
            buy = sell;
        } else {
            int profit = prices[sell] - prices[buy];
            maxProfit = MAX(profit, maxProfit);
        }
        sell++;
    }

    return maxProfit;
}
// @leet end
