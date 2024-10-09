// @leet start
#include <math.h>

int getMax(int* input, int n) {
    if (n < 0) {
        return 0;
    }
    else if (n <= 1) {
        return input[0];
    }

    int max = input[0];

    for (int i = 1; i < n; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }

    return max;
}

int binarySearch(int* piles, int l, int r, int h, int pilesSize, int previousK) {
    if (l > r) {
        return previousK;
    }

    int middle = l + (r - l) / 2;

    double totalHours = 0;
    for (int i = 0; i < pilesSize; i++) {
        double pileHours = ceil(piles[i] / (double)middle);
        totalHours += pileHours;
    }

    if (totalHours > h) {
        return binarySearch(piles, middle + 1, r, h, pilesSize, previousK);
    } else {
        return binarySearch(piles, l, middle - 1, h, pilesSize, middle);
    }

    return middle;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    return binarySearch(piles, 1, getMax(piles, pilesSize), h, pilesSize, 0);
}
// @leet end
