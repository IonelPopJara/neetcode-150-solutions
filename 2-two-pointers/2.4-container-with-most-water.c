// @leet start
int maxArea(int* height, int heightSize) {
    int max = -1;

    int l = 0;
    int r = heightSize - 1;

    while (l < r) {
        int currentArea = height[l] > height[r] ? height[r] * (r - l) : height[l] * (r - l);

        if (currentArea > max) {
            max = currentArea;
        }

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }

    return max;
}
// @leet end
